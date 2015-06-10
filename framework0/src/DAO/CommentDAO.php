<?php

namespace Framework0\DAO;

use Framework0\Domain\Comment;

class CommentDAO extends DAO 
{
	private $articleDAO; // type \Framework0\DAO\ArticleDAO
	private $userDAO; // type \Framework0\DAO\UserDAO

	public function setArticleDAO(ArticleDAO $articleDAO) { $this->articleDAO = $articleDAO; }
	public function setUserDAO(UserDAO $userDAO) { $this->userDAO = $userDAO; }

	public function findAllByArticle($articleId) // find all comment by art_id
	{
		// The associated article is retrieved only once
		$article = $this->articleDAO->find($articleId);

		// art_id is not selected by the SQL query
		// The article won't be retrieved during domain objet construction
		$query = "SELECT com_id, com_content, usr_id FROM t_comment WHERE art_id=? ORDER BY com_id";
		$ret = $this->getDb()->fetchAll($query, array($articleId));

		// Convert query ret to an array of domain objects
		$comments = array();
		foreach ($ret as $row)
		{
			$comId = $row['com_id'];
			$comment = $this->buildDomainObject($row);
			// The associated article is defined for the constructed comment
			$comment->setArticle($article);
			$comments[$comId] = $comment;
		}
		return $comments;
	}

	public function findAll()
	{
		$query = "SELECT * FROM t_comment ORDER BY com_id DESC";
		$ret = $this->getDb()->fetchAll($query);
		$newarr = array();
		foreach ($ret as $k)
		{
			$id = $k['com_id'];
			$newarr[$id] = $this->buildDomainObject($k);
		}
		return $newarr;
	}

	public function find($id) {
		$query = "SELECT * FROM t_comment WHERE com_id=?";
		$ret = $this->getDb()->fetchAssoc($query, array($id));
		if ($ret)
			return $this->buildDomainObject($ret);
		throw new \Exception("No comment matching id " . $id);
	}

	public function save(Comment $comment) // save a comment
	{
		$commentData = array(
			'art_id' => $comment->getArticle()->getId(),
			'usr_id' => $comment->getAuthor()->getId(),
			'com_content' => $comment->getContent()
			);
		if ($comment->getId()) // comment exist : update it
			$this->getDb()->update('t_comment', $commentData, array('com_id' => $comment->getId()));
		else // comment dont exist : create it
		{
			$this->getDb()->insert('t_comment', $commentData);
			// Get the id of the new created comment and set it on the entity.
			$id = $this->getDb()->lastInsertId();
			$comment->setId($id);
		}
	}

	public function deleteAllByArticle($articleId)
	{
		$this->getDb()->delete('t_comment', array('art_id' => $articleId));
	}

	public function delete($id)
	{
		$this->getDb()->delete('t_comment', array('com_id' => $id));
	}

	public function deleteAllByUser($userId)
	{
		$this->getDb()->delete('t_comment', array('usr_id' => $userId));
	}

	protected function buildDomainObject($row) // create a new comment (type \Framework0\Domain\Comment)
	{
		$comment = new Comment();
		$comment->setId($row['com_id']);
		$comment->setContent($row['com_content']);

		if (array_key_exists('art_id', $row))
		{
			// Find and set the associated article
			$articleId = $row['art_id'];
			$article = $this->articleDAO->find($articleId);
			$comment->setArticle($article);
		}
		if (array_key_exists('usr_id', $row))
		{
			// Find and set the associated author
			$userId = $row['usr_id'];
			$user = $this->userDAO->find($userId);
			$comment->setAuthor($user);
		}
		return $comment;
	}
}

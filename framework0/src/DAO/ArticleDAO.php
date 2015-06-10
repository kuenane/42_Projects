<?php

namespace Framework0\DAO;

use Framework0\Domain\Article;

class ArticleDAO extends DAO
{
	public function findAll() // return all articles sorted by date
	{
		$query = "SELECT * FROM t_article ORDER BY art_id DESC";
		$ret = $this->getDb()->fetchAll($query);
		$art_arr = array(); // Convert query ret to an array of domain objects
		foreach ($ret as $row)
		{
			$articleId = $row['art_id'];
			$art_arr[$articleId] = $this->buildDomainObject($row);
		}
		return $art_arr;
	}

	public function find($id) // search an article by his id (throw if no article found)
	{
		$query = "SELECT * FROM t_article WHERE art_id=?";
		$row = $this->getDb()->fetchAssoc($query, array($id));
		if ($row)
			return $this->buildDomainObject($row);
		throw new \Exception("No article matching id ".$id);
	}

	public function save(Article $article) // add an article
	{
		$articleData = array(
			'art_title' => $article->getTitle(),
			'art_content' => $article->getContent(),
			'art_prev' => $article->getPreview(),
			'art_subj' => $article->getSubject(),
			);

		if ($article->getId()) // article already exist : update it
			$this->getDb()->update('t_article', $articleData, array('art_id' => $article->getId()));
		else // else create it
		{
			$this->getDb()->insert('t_article', $articleData);
			$id = $this->getDb()->lastInsertId();
			$article->setId($id);
		}
	}

	public function delete($id) // remove an article
	{
		$this->getDb()->delete('t_article', array('art_id' => $id));
	}

	protected function buildDomainObject($row) // create a new article (type \Framework0\Domain\Article)
	{
		$new_art = new Article();
		$new_art->setId($row['art_id']);
		$new_art->setTitle($row['art_title']);
		$new_art->setContent($row['art_content']);
		$new_art->setPreview($row['art_prev']);
		$new_art->setSubject($row['art_subj']);
		return $new_art;
	}
}

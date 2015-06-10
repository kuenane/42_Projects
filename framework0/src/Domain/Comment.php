<?php

	namespace Framework0\Domain;

	class Comment 
	{
		private $_id;
		private $_content;
		private $_article; // type \Framework0\Domain\Article
		private $_author; // type \MicroCMS\Domain\User

		public function getId() { return $this->_id; }
		public function getContent() { return $this->_content; }
		public function getArticle() { return $this->_article; }
		public function getAuthor() { return $this->_author; }

		public function setId($id) { $this->_id = $id; }
		public function setContent($content) { $this->_content = $content; }
		public function setArticle(Article $article) { $this->_article = $article; }
		public function setAuthor(User $author) { $this->_author = $author; }
	}

?>

<?php

namespace Framework0\Domain;

class Article 
{
    private $_id; // Article id (int)
    private $_title; // Article title (str)
    private $_content; // Article content (str)
    private $_preview; // Article preview (str)
    private $_subject; // Article subject (str)

    public function getId() {return $this->_id;}
    public function getTitle() {return $this->_title;}
    public function getContent() {return $this->_content;}
    public function getPreview() {return $this->_preview;}
    public function getSubject() {return $this->_subject;}

    public function setId($id) {$this->_id = $id;}
    public function setTitle($title) {$this->_title = $title;}
    public function setContent($content) {$this->_content = $content;}
    public function setPreview($preview) {$this->_preview = $preview;}
    public function setSubject($subject) {$this->_subject = $subject;}
}

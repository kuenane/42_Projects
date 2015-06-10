<?php

namespace Framework0\DAO;

use Doctrine\DBAL\Connection;

abstract class DAO 
{
    private $db; // type \Doctrine\DBAL\Connection

    public function __construct(Connection $db) { $this->db = $db; }

    protected function getDb() { return $this->db; }

    // pure function : must be overrided
    protected abstract function buildDomainObject($row);
}

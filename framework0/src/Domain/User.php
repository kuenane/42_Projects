<?php

namespace Framework0\Domain;

use Symfony\Component\Security\Core\User\UserInterface;

class User implements UserInterface
{
	private $_id; // type int
	private $_username; // type str
	private $_password; // type str
	private $_salt; // type str
	private $_role; // type str (ROLE_USER or ROLE_ADMIN)

	public function getId() { return $this->_id; }
	public function getUsername() { return $this->_username; } // needed by Symfony UserInterface
	public function getPassword() { return $this->_password; } // needed by Symfony UserInterface
	public function getSalt() { return $this->_salt; } // needed by Symfony UserInterface
	public function getRole() { return $this->_role; }
	public function getRoles() { return array($this->getRole()); } // needed by Symfony UserInterface

	public function setId($id) { $this->_id = $id; }
	public function setUsername($username) { $this->_username = $username; }
	public function setPassword($password) { $this->_password = $password; }
	public function setSalt($salt) { $this->_salt = $salt; }
	public function setRole($role) { $this->_role = $role; }

	public function eraseCredentials() // needed by Symfony UserInterface
	{
		// Nothing to do here
	}
}

<?php

namespace Framework0\DAO;

use Symfony\Component\Security\Core\User\UserInterface;
use Symfony\Component\Security\Core\User\UserProviderInterface;
use Symfony\Component\Security\Core\Exception\UsernameNotFoundException;
use Symfony\Component\Security\Core\Exception\UnsupportedUserException;
use Framework0\Domain\User;

class UserDAO extends DAO implements UserProviderInterface
{
	public function findAll()
	{
		$query = "SELECT * FROM t_user ORDER BY usr_role, usr_name";
		$result = $this->getDb()->fetchAll($query);
		$newarr = array();
		foreach ($result as $k)
		{
			$id = $k['usr_id'];
			$newarr[$id] = $this->buildDomainObject($k);
		}
		return $newarr;
	}

	public function find($id) // return user or throw
	{
		$query = "SELECT * FROM t_user WHERE usr_id=?";
		$row = $this->getDb()->fetchAssoc($query, array($id));
		if ($row)
			return $this->buildDomainObject($row);
		throw new \Exception("No user matching id " . $id);
	}

	public function loadUserByUsername($username) // need by Symfony
	{
		$query = "SELECT * FROM t_user WHERE usr_name=?";
		$row = $this->getDb()->fetchAssoc($query, array($username));
		if ($row)
			return $this->buildDomainObject($row);
		throw new UsernameNotFoundException(sprintf('User "%s" not found.', $username));
	}

	public function refreshUser(UserInterface $user) // need by Symfony
	{
		$class = get_class($user);
		if (!$this->supportsClass($class))
			throw new UnsupportedUserException(sprintf('Instances of "%s" are not supported.', $class));
		return $this->loadUserByUsername($user->getUsername());
	}

	public function save(User $user)
	{
		$userData = array(
			'usr_name' => $user->getUsername(),
			'usr_salt' => $user->getSalt(),
			'usr_password' => $user->getPassword(),
			'usr_role' => $user->getRole()
			);

		if ($user->getId()) // user already exist : update it
			 $this->getDb()->update('t_user', $userData, array('usr_id' => $user->getId()));
		else // else create it
		{
			$this->getDb()->insert('t_user', $userData);
			$id = $this->getDb()->lastInsertId();
			$user->setId($id);
		}
	}

	public function save_force_user(User $user)
	{
		$userData = array(
			'usr_name' => $user->getUsername(),
			'usr_salt' => $user->getSalt(),
			'usr_password' => $user->getPassword(),
			'usr_role' => 'ROLE_USER'
			);

		if ($user->getId()) // user already exist : update it
			 $this->getDb()->update('t_user', $userData, array('usr_id' => $user->getId()));
		else // else create it
		{
			$this->getDb()->insert('t_user', $userData);
			$id = $this->getDb()->lastInsertId();
			$user->setId($id);
		}
	}

	public function delete($id) { $this->getDb()->delete('t_user', array('usr_id' => $id)); }

	public function supportsClass($class) // need by Symfony
	{
		return 'Framework0\Domain\User' === $class;
	}

	protected function buildDomainObject($row) // create a new user (type \Framework0\Domain\User)
	{
		$new_user = new User();
		$new_user->setId($row['usr_id']);
		$new_user->setUsername($row['usr_name']);
		$new_user->setPassword($row['usr_password']);
		$new_user->setSalt($row['usr_salt']);
		$new_user->setRole($row['usr_role']);
		return $new_user;
	}
}

<?php

use Symfony\Component\HttpFoundation\Request;
use Framework0\Domain\Comment;
use Framework0\Form\Type\CommentType;
use Framework0\Domain\Article;
use Framework0\Form\Type\ArticleType;
use Framework0\Domain\User;
use Framework0\Form\Type\UserType;
use Framework0\Form\Type\RegisterType;

// Home page
	$app->get('/', function () use ($app)
	{
		$articles = $app['dao.article']->findAll();
		return $app['twig']->render('index.html.twig', array('articles' => $articles));
	});
//

// Article details with comments
	$app->match('/article/{id}', function ($id, Request $request) use ($app)
	{
		$article = $app['dao.article']->find($id);
		$user = $app['security']->getToken()->getUser();
		$commentFormView = null;
		if ($app['security']->isGranted('IS_AUTHENTICATED_FULLY'))
		{
			// A user is fully authenticated : he can add comments
			$comment = new Comment();
			$comment->setArticle($article);
			$comment->setAuthor($user);
			$commentForm = $app['form.factory']->create(new CommentType(), $comment);
			$commentForm->handleRequest($request);
			if ($commentForm->isSubmitted() && $commentForm->isValid())
			{
				$app['dao.comment']->save($comment);
				$app['session']->getFlashBag()->add('success', 'Your comment was succesfully added.');
			}
			$commentFormView = $commentForm->createView();
		}
		$comments = $app['dao.comment']->findAllByArticle($id);
		return $app['twig']->render('article.html.twig', array(
			'article' => $article, 
			'comments' => $comments,
			'commentForm' => $commentFormView));
	});
//

// Login form
	$app->get('/login', function(Request $request) use ($app)
	{
		return $app['twig']->render('login.html.twig', array(
			'error' => $app['security.last_error']($request),
			'last_username' => $app['session']->get('_security.last_username'),
		));
	})->bind('login');
//

// Admin page
	$app->get('/admin', function() use($app)
	{
		$articles = $app['dao.article']->findAll();
		$comments = $app['dao.comment']->findAll();
		$users = $app['dao.user']->findAll();
		return $app['twig']->render('admin.html.twig', array(
			'articles' => $articles,
			'comments' => $comments,
			'users' => $users));
	});
//

// add article
	$app->match('/admin/article/add', function(Request $request) use ($app)
	{
		$new_art = new Article();
		$articleForm = $app['form.factory']->create(new ArticleType(), $new_art);
		$articleForm->handleRequest($request);
		if ($articleForm->isSubmitted() && $articleForm->isValid())
		{
			$app['dao.article']->save($new_art);
			$app['session']->getFlashBag()->add('success', 'The article was successfully added.');
		}
		return $app['twig']->render('article_form.html.twig', array(
			'title' => 'New article',
			'articleForm' => $articleForm->createView()));
	});
//

// edit article
	$app->match('/admin/article/{id}/edit', function($id, Request $request) use ($app)
	{
		$article = $app['dao.article']->find($id);
		$articleForm = $app['form.factory']->create(new ArticleType(), $article);
		$articleForm->handleRequest($request);
		if ($articleForm->isSubmitted() && $articleForm->isValid())
		{
			$app['dao.article']->save($article);
			$app['session']->getFlashBag()->add('success', 'The article was succesfully updated.');
		}
		return $app['twig']->render('article_form.html.twig', array(
			'title' => 'Edit article',
			'articleForm' => $articleForm->createView()));
	});
//

// rm article
	$app->get('/admin/article/{id}/delete', function($id, Request $request) use ($app)
	{
		$app['dao.comment']->deleteAllByArticle($id); // rm associated comments
		$app['dao.article']->delete($id);
		$app['session']->getFlashBag()->add('success', 'The article was succesfully removed.');
		return $app->redirect('/admin');
	});
//

// edit comment
	$app->match('/admin/comment/{id}/edit', function($id, Request $request) use ($app)
	{
		$comment = $app['dao.comment']->find($id);
		$commentForm = $app['form.factory']->create(new CommentType(), $comment);
		$commentForm->handleRequest($request);
		if ($commentForm->isSubmitted() && $commentForm->isValid())
		{
			$app['dao.comment']->save($comment);
			$app['session']->getFlashBag()->add('success', 'The comment was succesfully updated.');
		}
		return $app['twig']->render('comment_form.html.twig', array(
			'title' => 'Edit comment',
			'commentForm' => $commentForm->createView()));
	});
//

// rm comment
	$app->get('/admin/comment/{id}/delete', function($id, Request $request) use ($app)
	{
		$app['dao.comment']->delete($id);
		$app['session']->getFlashBag()->add('success', 'The comment was succesfully removed.');
		return $app->redirect('/admin');
	});
//

// register
	$app->match('/register', function(Request $request) use ($app)
	{
		$user = new User();
		$userForm = $app['form.factory']->create(new RegisterType(), $user);
		$userForm->handleRequest($request);
		if ($userForm->isSubmitted() && $userForm->isValid())
		{
			$salt = substr(md5(time()), 0, 23); // generate a random salt value
			$user->setSalt($salt);
			$plainPassword = $user->getPassword();
			$encoder = $app['security.encoder.digest']; // find the default encoder
			$password = $encoder->encodePassword($plainPassword, $user->getSalt()); // compute the encoded password
			$user->setPassword($password); 
			$app['dao.user']->save_force_user($user);
			$app['session']->getFlashBag()->add('success', 'The user was successfully created.');
		}
		return $app['twig']->render('register_form.html.twig', array(
			'title' => 'New user',
			'userForm' => $userForm->createView()));
	});

// add user by admin
	$app->match('/admin/user/add', function(Request $request) use ($app)
	{
		$user = new User();
		$userForm = $app['form.factory']->create(new UserType(), $user);
		$userForm->handleRequest($request);
		if ($userForm->isSubmitted() && $userForm->isValid())
		{
			$salt = substr(md5(time()), 0, 23); // generate a random salt value
			$user->setSalt($salt);
			$plainPassword = $user->getPassword();
			$encoder = $app['security.encoder.digest']; // find the default encoder
			$password = $encoder->encodePassword($plainPassword, $user->getSalt()); // compute the encoded password
			$user->setPassword($password); 
			$app['dao.user']->save($user);
			$app['session']->getFlashBag()->add('success', 'The user was successfully created.');
		}
		return $app['twig']->render('user_form.html.twig', array(
			'title' => 'New user',
			'userForm' => $userForm->createView()));
	});

// edit user by admin
	$app->match('/admin/user/{id}/edit', function($id, Request $request) use ($app)
	{
		$user = $app['dao.user']->find($id);
		$userForm = $app['form.factory']->create(new UserType(), $user);
		$userForm->handleRequest($request);
		if ($userForm->isSubmitted() && $userForm->isValid())
		{
			$plainPassword = $user->getPassword();		
			$encoder = $app['security.encoder_factory']->getEncoder($user); // find the encoder for the user
			$password = $encoder->encodePassword($plainPassword, $user->getSalt()); // compute the encoded password
			$user->setPassword($password); 
			$app['dao.user']->save($user);
			$app['session']->getFlashBag()->add('success', 'The user was succesfully updated.');
		}
		return $app['twig']->render('user_form.html.twig', array(
			'title' => 'Edit user',
			'userForm' => $userForm->createView()));
	});

// rm user by admin
	$app->get('/admin/user/{id}/delete', function($id, Request $request) use ($app) {	
		$app['dao.comment']->deleteAllByUser($id); // Delete all associated comments
		$app['dao.user']->delete($id); // Delete the user
		$app['session']->getFlashBag()->add('success', 'The user was succesfully removed.');
		return $app->redirect('/admin');
	});

// contactus
	$app->get('/contact', function() use ($app)
	{
	$request = $app['request'];
	$message = \Swift_Message::newInstance()
		->setSubject('F0 Message')
		->setFrom(array('wide-aze@laposte.net'))
		->setTo(array('31dw31@gmail.com'))
		->setBody($request->get('message'));
	$app['mailer']->send($message);
	return $app['twig']->render('contact.html.twig', array(
		'title' => 'Contact'));
	})->bind('contact');

?>

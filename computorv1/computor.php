#!/usr/bin/php
<?php

include './ft_math.php';
include './pre_op.php';
include './op.php';

// PRE_VERIFICATIONS
	if (empty($argc) || empty($argv[1]) || $argc != 2)
		exit("Invalid input".PHP_EOL);
	if (count ($arr = explode('=', trim($argv[1], ' '))) !== 2)
		exit("Invalid input".PHP_EOL);
	pre_parse_it($arr);
//

// PRE_OPERATIONS
	$left = split_and_natural_form($arr[0]);
	$right = split_and_natural_form($arr[1]);
	parse_it($left, $right);
	everything_to_left($left, $right);
	group_by_pow($left);
	sort_by_pow_and_unset_zero($left);
//

// OPERATIONS
	all_nb_are_solution($left);
	print_reduced($left);
	$degree = print_and_give_degree($left);
//

// INTERPRET DEGREE
	if ($degree > 2)
		exit("The polynomial degree is stricly greater than 2, I can't solve.".PHP_EOL);
	if ($degree <= 0)
		exit("Unable to solve the equation.".PHP_EOL);
	if ($degree == 1)
		degree1($left, $right);
	else
		degree2($left);
//
?>

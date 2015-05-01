<?php

function 	pre_parse_it($arr)
{
	if (empty($arr[0]) || empty($arr[1]))
		exit("Invalid input".PHP_EOL);
	if (preg_match('/[^\s0123456789\+\-\*\.\^xX\=]/', $arr[0]))
		exit("Invalid input".PHP_EOL);
	if (preg_match('/[^\s0123456789\+\-\*\.\^xX\=]/', $arr[1]))
		exit("Invalid input".PHP_EOL);
}

function 	is_an_empty_array($array)
{
	foreach ($array as $k)
		if (strlen($k))
			return false;
	return true;
}

function	split_and_natural_form($arr)
{
	$arr = preg_replace('/\s+/', '', strtoupper($arr));
	if (preg_match('/\+\-/', $arr) || preg_match('/\-\+/', $arr) || preg_match('/\-\-/', $arr) || preg_match('/\+\+/', $arr))
		exit("Invalid input".PHP_EOL);
	preg_match_all('/([-+]?)([0-9]+\.?[0-9]*)?\*?(X\^?([0-9]+\.?[0-9]*)?)?/', $arr, $arr, PREG_SET_ORDER);
	foreach ($arr as $k => $v)
		if (is_an_empty_array($v))
			unset($arr[$k]);
	foreach ($arr as $k => $v)
	{
		if (!strlen($arr[$k][1]))
		{
			$arr[$k][0] = "+".$arr[$k][0];
			$arr[$k][1] = "+";
		}
		if (!isset($arr[$k][2]) || !strlen($arr[$k][2]))
		{
			$arr[$k][0] = substr_replace($arr[$k][0], "1*", 1, 0);
			$arr[$k][2] = "1";
		}
		if (!isset($arr[$k][3]))
		{
			if (preg_match('/\*/', $arr[$k][0]))
				$arr[$k][0] = $arr[$k][0]."X";
			else
				$arr[$k][0] = $arr[$k][0]."*X";
			$arr[$k][3] = "X";
			if (!isset($arr[$k][4]))
			{
				$arr[$k][0] = $arr[$k][0]."^0";
				$arr[$k][3] = $arr[$k][3]."^0";
				$arr[$k][4] = "0";
			}
		}
		if (!isset($arr[$k][4]))
		{
			$arr[$k][0] = $arr[$k][0]."^1";
			$arr[$k][3] = $arr[$k][3]."^1";
			$arr[$k][4] = "1";
		}
	}
	return ($arr);
}

function	parse_it($left, $right)
{
	foreach ($left as $lft)
	{
		if (preg_match_all('/^[+-]{1}[0-9]+(\.[0-9]+)?\*X\^[0-9]+$/', $lft[0]) !== 1)
			exit("Invalid input".PHP_EOL);
		if ($lft[1] !== '+' && $lft[1] !== '-')
			exit("Invalid input".PHP_EOL);
		if (preg_match_all('/^[0-9]+(\.[0-9]+)?/', $lft[2]) !== 1)
			exit("Invalid input".PHP_EOL);
		if (preg_match_all('/^X\^[0-9]+$/', $lft[3]) !== 1)
			exit("Invalid input".PHP_EOL);
		if (preg_match_all('/^[0-9]+$/', $lft[4]) !== 1)
			exit("Invalid input".PHP_EOL);
	}
	foreach ($right as $rgt)
	{
		if (preg_match_all('/^[+-]{1}[0-9]+(\.[0-9]+)?\*X\^[0-9]+$/', $rgt[0]) !== 1)
			exit("Invalid input".PHP_EOL);
		if ($rgt[1] !== '+' && $rgt[1] !== '-')
			exit("Invalid input".PHP_EOL);
		if (preg_match_all('/^[0-9]+(\.[0-9]+)?/', $rgt[2]) !== 1)
			exit("Invalid input".PHP_EOL);
		if (preg_match_all('/^X\^[0-9]+$/', $rgt[3]) !== 1)
			exit("Invalid input".PHP_EOL);
		if (preg_match_all('/^[0-9]+$/', $rgt[4]) !== 1)
			exit("Invalid input".PHP_EOL);
	}
}

function everything_to_left(&$left, &$right)
{
	foreach ($right as $k => $v)
	{
		if ($right[$k][0][0] === '+')
			$right[$k][0][0] = '-';
		else
			$right[$k][0][0] = '+';
		$right[$k][1][0] = $right[$k][0][0];
		$left[] = $right[$k];
		unset($right[$k]);
	}
}

function group_by_pow_merge(&$newk, $cur)
{
	$a = $newk[2];
	if ($newk[1] === '-')
		$a *= -1;
	$b = $cur[2];
	if ($cur[1] === '-')
		$b *= -1;
	$newk[1] = ft_sign($a + $b);
	$newk[2] = (string)ft_abs($a + $b);
	$newk[0] = substr_replace($newk[0], $newk[1].$newk[2], 0, strlen($newk[2]) + 1);
}

function group_by_pow_add(&$new, $cur)
{
	foreach ($new as $k => $v)
	{
		if ($cur[4] === $v[4])
		{
			group_by_pow_merge($new[$k], $cur);
			return ;
		}
	}
	$new[] = $cur;
}

function group_by_pow(&$left)
{
	$new = array();
	foreach($left as $k => $v)
		group_by_pow_add($new, $v);
	$left = $new;
}

function sort_by_pow_and_unset_zero(&$left)
{
	usort($left, function($a, $b) { return strcmp($a[4], $b[4]); } ); 
	foreach ($left as $k => $v)
	{
		if (!$v[2])
			unset($left[$k]);
	}
}

?>

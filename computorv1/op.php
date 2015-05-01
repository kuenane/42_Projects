<?php

function all_nb_are_solution($left)
{
	if (!count($left))
		exit("\033[32mAll real numbers are solution...\033[0m".PHP_EOL);
}

function print_reduced($left)
{
	$isfirst = true;
	$str = '';
	foreach($left as $k => $v)
	{
		if ($isfirst == true)
		{
			$isfirst = false;
			if ($v[1] === '-')
				$str = $str.'-';
		}
		else
			$str = $str.' '.$v[1].' ';
		if ($v[4] == '0' || $v[2] !== '1')
			$str = $str.$v[2];
		if ($v[4] != '0')
		{
			if ($v[4] != '1')
				$str = $str.$v[3];
			else
				$str = $str.'X';
		}
	}
	echo "\033[32mReduced form: ".$str." = 0\033[0m".PHP_EOL;
}

function print_and_give_degree($left)
{
	$degree = $left[0][4];
	foreach($left as $k)
		if ($k[4] > $degree)
			$degree = $k[4];
	echo "Polynomial degree: ".$degree.PHP_EOL.PHP_EOL;
	return $degree;
}

function degree1(&$left, &$right)
{
	foreach ($left as $k => $v)
	{
		if ($v[4] === '1')
			continue;
		if ($left[$k][0][0] === '+')
			$left[$k][0][0] = '-';
		else
			$left[$k][0][0] = '+';
		$left[$k][1][0] = $left[$k][0][0];
		$right[] = $left[$k];
		unset($left[$k]);
	}
	if (!count($right))
		exit("\033[31mThe solution is: 0\033[0m".PHP_EOL);
	$nb1 = 0;
	foreach ($left as $k)
	{
		$cur = $k[2];
		if ($k[1] == '-')
			$cur *= -1;
		$nb1 += $cur;
	}
	$nb2 = 0;
	foreach ($right as $k)
	{
		$cur = $k[2];
		if ($k[1] == '-')
			$cur *= -1;
		$nb2 += $cur;
	}
	exit("\033[31mThe solution is: ".($nb2 / $nb1).PHP_EOL."\033[0m[ $nb2 / $nb1 = ".$nb2 / $nb1." ]".PHP_EOL);
}

function degree2($left)
{
	$a = 0;
	$b = 0;
	$c = 0;
	foreach ($left as $k)
	{
		if ($k[4] === '0')
		{
			$c = $k[2];
			if ($k[1] === '-')
				$c *= -1;
		}
		else if ($k[4] === '1')
		{
			$b = $k[2];
			if ($k[1] === '-')
				$b *= -1;
		}
		else if ($k[4] === '2')
		{
			$a = $k[2];
			if ($k[1] === '-')
				$a *= -1;
		}
	}
	$delta = $b * $b - 4 * $a * $c;
	$str = '';
	if ($delta < 0)
	{
		$ret1 = -$b / 2 * $a;
		$ret2 = ft_abs(ft_sqrt(-$delta) / (2 * $a));
		if ($ret2 == 1)
			$ret2 = '';
		else
			$ret2 = " * ".$ret2;
		$str = "\033[35mDiscriminant is strictly negative: ".$delta.PHP_EOL."\033[0m[ $b * $b - 4 * $a * $c = ".($b * $b - 4 * $a * $c)." ]".PHP_EOL.PHP_EOL;
		$str = $str."\033[31mThe two complexes solutions are: ".$ret1." + i".$ret2." and ".$ret1." - i".$ret2.PHP_EOL."\033[0m[ N1($b / 2 * $a = ".(-$b / 2 * $a).") N2(ft_abs(ft_sqrt($delta) / (2 * $a)) = ".ft_abs(ft_sqrt(-$delta) / (2 * $a)).") ]";
	}
	else if ($delta === 0)
	{
		$str = "\033[35mDiscriminant is null: 0".PHP_EOL."\033[0m[ $b * $b - 4 * $a * $c = ".($b * $b - 4 * $a * $c)." ]".PHP_EOL.PHP_EOL;
		$str = $str."\033[31mThe solution is : ".(-$b / 2 * $a).PHP_EOL."\033[0m[ $b / 2 * $a = ".(-$b / 2 * $a)." ]";
	}
	else if ($delta > 0)
	{
		$str = "\033[35mDiscriminant is strictly positive: ".$delta.PHP_EOL."\033[0m[ $b * $b - 4 * $a * $c = ".($b * $b - 4 * $a * $c)." ]".PHP_EOL;
		$str = $str.PHP_EOL."\033[31mThe solution is : ".((-$b + ft_sqrt($delta)) / (2 * $a))." and ".((-$b - ft_sqrt($delta)) / (2 * $a));
		$str = $str.PHP_EOL."\033[0m[ ($b + ft_sqrt($delta)) / (2 * $a) = ".((-$b + ft_sqrt($delta)) / (2 * $a))." ]";
		$str = $str.PHP_EOL."[ ($b - ft_sqrt($delta)) / (2 * $a) = ".((-$b - ft_sqrt($delta)) / (2 * $a))." ]";
	}
	exit($str.PHP_EOL);
}
?>

<?php

function ft_abs($a)
{
	if ($a > 0)
		return ($a);
	return (-$a);
}

function ft_sign($a)
{
	if ($a >= 0)
		return ('+');
	return ('-');
}

function ft_sqrt($a)
{
	if ($a < 0)
		return (FALSE);
	$x = $a / 2;
 	while (ft_abs($x * $x - $a) > 0.0001)
 	{
 		$x = $x - ($x * $x - $a) / (2 * $x);
 	}
 	return ($x);
}

?>

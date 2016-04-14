let rec iter f x n =
	if (n < 0) then -1
	else if (n == 0) then x
	else iter f (f x) (n-1) 

let () =
	print_endline "Test with [x*x, 2, 4]:";
	print_int (iter (fun x -> x * x) 2 4);
	print_char '\n';
	print_endline "Test with [x*2, 2, 4]:";
	print_int (iter (fun x -> x * 2) 2 4);
	print_char '\n';
	print_endline "Test with [x*x, 2, -1]:";
	print_int (iter (fun x -> x * x) 2 (-1));
	print_char '\n'

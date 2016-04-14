let sum (f1:float) (f2:float) :float = f1 +. f2

let () =
	print_endline "Test with [sum 0. 1.]:";
	print_float (sum 0. 1.);
	print_char '\n';

	print_endline "Test with [sum 1. -1.]:";
	print_float (sum 1. (-1.));
	print_char '\n';

	print_endline "Test with [sum 1. infinity]:";
	print_float (sum 1. infinity);
	print_char '\n';

	print_endline "Test with [sum -24.24 neg_infinity]:";
	print_float (sum (-24.24) neg_infinity);
	print_char '\n';

	print_endline "Test with [sum 42.42 nan]:";
	print_float (sum 42.42 nan);
	print_char '\n';

	print_endline "Test with [sum 0. max_float]:";
	print_float (sum 0. max_float);
	print_char '\n';

	print_endline "Test with [sum 0. min_float]:";
	print_float (sum 0. min_float);
	print_char '\n';

	print_endline "Test with [sum 0. epsilon_float]:";
	print_float (sum 0. epsilon_float);
	print_char '\n'

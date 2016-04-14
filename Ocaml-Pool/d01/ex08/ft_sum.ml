let rec ft_sum f min max =
	let rec loop i acc = if (i > max) then acc else loop (i + 1) (acc +. (f i))	in
	if (min > max) then nan else loop min 0.

let () =
	print_endline "Test with [fun i -> float_of_int (i * i)) 1 1]:";
	print_float (ft_sum (fun i -> float_of_int (i * i)) 1 1);
	print_char '\n';

	print_endline "Test with [fun i -> float_of_int (i * i)) 1 10]:";
	print_float (ft_sum (fun i -> float_of_int (i * i)) 1 10);
	print_char '\n';

	print_endline "Test with [fun i -> float_of_int (i * i) 42 1]:";
	print_float (ft_sum (fun i -> float_of_int (i * i)) 42 1);
	print_char '\n'

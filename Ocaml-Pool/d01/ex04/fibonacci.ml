let fibonacci n =
	let rec loop n i j =
		if (n < 0) then	(-1)
		else if (n == 0) then i
		else loop (n - 1) (j) (i + j)
	in
	loop n 0 1


let () =
	print_endline "Test with [-42]:";
	print_int(fibonacci (-42));
	print_char '\n';
	print_endline "Test with [0]:";
	print_int(fibonacci 0);
	print_char '\n';
	print_endline "Test with [1]:";
	print_int(fibonacci 1);
	print_char '\n';
	print_endline "Test with [3]:";
	print_int(fibonacci 3);
	print_char '\n';
	print_endline "Test with [6]:";
	print_int(fibonacci 6);
	print_char '\n';
	print_endline "Test with [42]:";
	print_int(fibonacci 42);
	print_char '\n'

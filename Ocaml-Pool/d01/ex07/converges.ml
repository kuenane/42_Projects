let rec converges f x n =
	if (n < 0) then false
	else if (f x == x) then true
	else converges f (f x) (n-1) 

let () =
	let print_bool state = if (state == true) then "true" else "false" in
	print_endline "Test with [(( * ) 2) 2 5]:";

	print_endline (print_bool (converges (( * ) 2) 2 5));

	print_char '\n';
	print_endline "Test with [x/2, 2, 3]:";

	print_endline (print_bool (converges (fun x -> x / 2) 2 3));

	print_char '\n';
	print_endline "Test with [x/2, 2, 2]:";

	print_endline (print_bool (converges (fun x -> x / x) 2 2));

	print_char '\n'

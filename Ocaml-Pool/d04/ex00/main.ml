let () =
	let rec iter lst f = match lst with
		| head::tail -> print_string (f head) ; print_char ' ' ; iter tail f
		| [] -> print_char '\n'
	in

	print_endline "Test with [toString of Color.all]: ";
	iter Color.all Color.toString;
	print_endline "Test with [toStringVerbose of Color.all]: ";
	iter Color.all Color.toStringVerbose;

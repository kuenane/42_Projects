let () =
	let rec iter lst f g = match lst with
		| head::tail -> g (f head) ; print_char ' ' ; iter tail f g
		| [] -> print_char '\n'
	in

	print_endline "Test with [toInt of Value.all]: ";
	iter Value.all Value.toInt print_int;
	print_char '\n';

	print_endline "Test with [toString of Value.all]: ";
	iter Value.all Value.toString print_string;
	print_char '\n';

	print_endline "Test with [toStringVerbose of Value.all]: ";
	iter Value.all Value.toStringVerbose print_string;
	print_char '\n';

	print_endline "Test with [toStringVerbose (next T2)]: ";
	print_endline (Value.toStringVerbose (Value.next Value.T2));
	print_char '\n';

	print_endline "Test with [toStringVerbose (next T10)]: ";
	print_endline (Value.toStringVerbose (Value.next Value.T10));
	print_char '\n';

	print_endline "Test with [toStringVerbose (next As)]: /!\\ UNCOMMENT THE CODE TO CHECK EXCEPTION";
	(* print_endline (Value.toStringVerbose (Value.next Value.As)); *)
	print_char '\n';

	print_endline "Test with [toStringVerbose (previous T2)]: /!\\ UNCOMMENT THE CODE TO CHECK EXCEPTION";
	(* print_endline (Value.toStringVerbose (Value.previous Value.T2)); *)
	print_char '\n';

	print_endline "Test with [toStringVerbose (previous T10)]: ";
	print_endline (Value.toStringVerbose (Value.previous Value.T10));
	print_char '\n';

	print_endline "Test with [toStringVerbose (previous As)]: ";
	print_endline (Value.toStringVerbose (Value.previous Value.As));

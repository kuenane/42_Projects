let rec repeat_string ?str:(str="x") n =
	if (n < 0) then "Error"
	else if (n = 0) then ""
	else str ^ repeat_string ~str:str (n - 1)

let () =
	print_endline "Test with [-42]: ";
	print_endline (repeat_string (-42));
	print_endline "Test with [0]: ";
	print_endline (repeat_string 0);
	print_endline "Test with [1]: ";
	print_endline (repeat_string 1);
	print_endline "Test with [42]: ";
	print_endline (repeat_string 42);
	print_endline "Test with [-42, 'pouet']: ";
	print_endline (repeat_string ~str:"pouet" (-42));
	print_endline "Test with [0, 'pouet']: ";
	print_endline (repeat_string ~str:"pouet" 0);
	print_endline "Test with [1, 'pouet']: ";
	print_endline (repeat_string ~str:"pouet" 1);
	print_endline "Test with [42, 'pouet']: ";
	print_endline (repeat_string ~str:"pouet" 42);

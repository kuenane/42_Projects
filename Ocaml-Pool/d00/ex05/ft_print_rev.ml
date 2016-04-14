let ft_print_rev str =
	let rec loop str n =
		if (n >= 0) then
			print_char (String.get str n);
		if (n > 0) then
			loop str (n - 1) in
	loop str (String.length str - 1);
	print_char '\n'

let main () =
	print_endline "Test with ['Hello World !']: ";
	ft_print_rev "Hello World !";
	print_endline "Test with ['']: ";
	ft_print_rev "";
	print_endline "Test with ['42']: ";
	ft_print_rev "42"

let () = main ()

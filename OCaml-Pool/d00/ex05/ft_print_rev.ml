let ft_print_rev str =
begin
	let length = (String.length str) in
	let rec print_rev str i =
		if i > 0 then
			begin
				print_char (String.get str (i - 1));
				print_rev str (i - 1)
			end
	in
	print_rev str length;
	print_char '\n'
end

let main () =
begin
	print_endline "Test with ['Hello World!']:";
	ft_print_rev ("Hello World!");
	print_endline "Test with ['I Love OCaml']:";
	ft_print_rev ("I Love OCaml")
end

(* ************************************************************************** *)

let () = main()

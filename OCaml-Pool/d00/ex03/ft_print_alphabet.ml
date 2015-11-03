let ft_print_alphabet () =
begin
	let first = int_of_char 'a' in
	let last = int_of_char 'z' in
	let rec loop cur =
		if (cur <= last) then
			begin
				print_char (char_of_int cur);
				loop (cur + 1)
			end in
		loop first;
		print_char '\n'
end

let main () =
begin
	ft_print_alphabet ()
end

(* ************************************************************************** *)

let () = main()

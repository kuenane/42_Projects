let ft_print_alphabet () =
begin
	let stop = int_of_char 'z' in
	let rec alph cur =
		print_char (char_of_int cur);
		if (cur < stop) then
			alph (cur + 1) in
	alph (int_of_char 'a');
	print_char '\n'
end

let () = ft_print_alphabet ()

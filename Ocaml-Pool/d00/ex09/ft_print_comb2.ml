let ft_print_comb2 () =
	let print_nb x = print_int (x / 10) ; print_int (x mod 10) in
	let rec loop a b =
		if (a < b) then begin 
		print_nb a;
		print_char ' ';
		print_nb b;
		if (a < 98) then begin print_char ',';print_char ' ' end;
		end;
		if (a < 99 && b == 99) then
			loop (a + 1) 0
		else if (a < 99) then
			loop a (b+1)
	in
	loop 0 1;
	print_char '\n'

let () = ft_print_comb2 ()

let ft_print_comb () =
begin
	let rec loop a b c =
	begin
		print_int a ; print_int b ; print_int c;
		if (a < 7) then
		begin
			print_string ", ";
			if (b == 8) then
				loop (a+1) (a+2) (a+3)
			else
				if (c == 9) then
					loop a (b+1) (b+2)
				else
					loop a b (c+1)
		end
	end in
	loop 0 1 2;
	print_string "\n"
end

let () = ft_print_comb ()

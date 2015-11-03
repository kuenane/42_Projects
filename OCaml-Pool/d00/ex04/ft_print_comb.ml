let ft_print_comb() =
	let rec comb a b c =
		print_int a ; print_int b ; print_int c;
		if (a <> 7) then
			begin
				print_string ", ";
				if (b == 8) then
					comb (a + 1) (a + 2) c
				else 
					begin
						if (c == 9) then
							comb a (b + 1) (b + 2)
						else
							comb a b (c + 1)
					end
			end
	in
	comb 0 1 2;
	print_string "\n"

let main () =
begin
	ft_print_comb ()
end

(* ************************************************************************** *)

let () = main()

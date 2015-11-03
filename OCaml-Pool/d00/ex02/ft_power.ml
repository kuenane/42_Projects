let rec ft_power nb pow =
begin
		if (pow > 0) then
			nb * ft_power nb (pow - 1)
		else
			1
end

let main () =
begin
	print_string("Test with [1, 1]: ");
	print_int(ft_power (1) (1));
	print_char('\n');
	print_string("Test with [0, 2]: ");
	print_int(ft_power (0) (2));
	print_char('\n');
	print_string("Test with [3, 0]: ");
	print_int(ft_power (3) (0));
	print_char('\n');
	print_string("Test with [2, 2]: ");
	print_int(ft_power (2) (2));
	print_char('\n')
end

(* ************************************************************************** *)

let () = main()

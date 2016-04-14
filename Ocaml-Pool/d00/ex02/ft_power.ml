let rec ft_power nb pow =
	if pow > 0 then
		nb * ft_power nb (pow - 1)
	else
		1

let main () =
begin
	print_string "Test with [2,4]: ";
	print_int (ft_power 2 4);
	print_char '\n';
	print_string "Test with [3,0]: ";
	print_int (ft_power 3 0);
	print_char '\n';
	print_string "Test with [0,5]: ";
	print_int (ft_power 0 5);
	print_char '\n';
end

(* ************************************************************************** *)

let () = main()

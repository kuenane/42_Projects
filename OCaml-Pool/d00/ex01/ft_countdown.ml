let rec ft_countdown nb =
begin
	if (nb < 0) then
		print_int (0)
	else
		print_int (nb);
		print_char '\n';
		if (nb > 0) then
			ft_countdown (nb - 1)
end

let main () =
begin
	print_endline "Test with [3]:";
	ft_countdown (3);
	print_endline "Test with [1]:";
	ft_countdown (1);
	print_endline "Test with [0]:";
	ft_countdown (0);
	print_endline "Test with [-1]:";
	ft_countdown (-1)
end

(* ************************************************************************** *)

let () = main()

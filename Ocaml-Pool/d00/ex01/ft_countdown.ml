let rec ft_countdown nb =
	if nb > 0 then
		print_int nb
	else
		print_int 0;
	print_char '\n';
	if nb > 0 then
		ft_countdown (nb - 1)

let main () =
begin
	print_endline "Test with [3]: ";
	ft_countdown (3);
	print_endline "Test with [0]: ";
	ft_countdown (0);
	print_endline "Test with [-3]: ";
	ft_countdown (-3)
end

(* ************************************************************************** *)

let () = main()

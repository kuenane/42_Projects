let ft_test_sign nb =
begin
	if nb < 0 then
		print_endline "negative"
	else
		print_endline "positive"
end

let main () =
begin
	print_string "Test with [100]: ";
	ft_test_sign (100);
	print_string "Test with [0]: ";
	ft_test_sign (0);
	print_string "Test with [-100]: ";
	ft_test_sign (-100)
end

(* ************************************************************************** *)

let () = main()

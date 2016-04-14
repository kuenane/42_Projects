let ft_string_all is_digit str =
	let rec loop is_digit str cur =
		if (cur == String.length str) then
			true
		else
			if (is_digit (String.get str cur)) then
				loop is_digit str (cur + 1)
			else
				false 
		in
	loop is_digit str 0	

let is_digit c = c >= '0' && c <= '9'

let main () =
begin
	print_endline "Test with ['4']:";
	if (ft_string_all is_digit "4") then
		print_endline "true"
	else
		print_endline "false";
	print_endline "Test with ['a']:";
	if (ft_string_all is_digit "a") then
		print_endline "true"
	else
		print_endline "false";
	print_endline "Test with ['0123456789']:";
	if (ft_string_all is_digit "0123456789") then
		print_endline "true"
	else
		print_endline "false";
	print_endline "Test with ['O12EAS67B9']:";
	if (ft_string_all is_digit "O12EAS67B9") then
		print_endline "true"
	else
		print_endline "false";
end

let () = main()

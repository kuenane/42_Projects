let ft_is_palindrome str =
begin
	let rec loop str a b =
	begin
		if (a >= b) then
			true
		else if (String.get str a) <> (String.get str b) then
			false
		else
			loop str (a + 1) (b - 1)
	end in
	loop str 0 ((String.length str) - 1)
end

let main () =
begin
	print_endline "Test with ['natan']:";
	if (ft_is_palindrome "natan") then
		print_endline "true"
	else
		print_endline "false";
	print_endline "Test with ['otto']:";
	if (ft_is_palindrome "otto") then
		print_endline "true"
	else
		print_endline "false";
	print_endline "Test with ['toto']:";
	if (ft_is_palindrome "toto") then
		print_endline "true"
	else
		print_endline "false";
	print_endline "Test with ['']:";
	if (ft_is_palindrome "") then
		print_endline "true"
	else
		print_endline "false";
end

let () = main()

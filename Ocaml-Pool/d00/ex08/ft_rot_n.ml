let ft_rot_n n str =
begin
	let isletter k =
	begin
		let intc = int_of_char k in
		if ((intc >= 65 && intc <= 90) || (intc >= 97 && intc <= 122)) then
			true
		else
			false
	end in
	let rec rot_int y i =
	begin
		if (i > 0) then
			if (y == 122 || y == 90) then
				rot_int (y-25) (i-1)
			else
				rot_int (y+1) (i-1)
		else
			char_of_int (y)
	end in
	let rec rot_char c =
	begin
		if (isletter c) then
			rot_int (int_of_char c) n
		else
			c
	end in
	String.map rot_char str
end

let main () =
	print_endline "Test with [1, 'abcdefghijklmnopqrstuvwxyz']: ";
	print_endline (ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz");
	print_endline "Test with [0, 'zzZZZzz']: ";
	print_endline (ft_rot_n 0 "zzZZZzz");
	print_endline "Test with [13, '']: ";
	print_endline (ft_rot_n 13 "");
	print_endline "Test with [42, '42']: ";
	print_endline (ft_rot_n 42 "42");
	print_endline "Test with [222, 'toto']: ";
	print_endline (ft_rot_n 222 "toto")

let () = main ()

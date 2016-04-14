type 'a ft_ref = {mutable contents : 'a}

let return (a:'a) = {contents = a}

let get (a:'a ft_ref) = a.contents

let set (rf:'a ft_ref) (v:'a) = rf.contents <- v

let bind (a:'a ft_ref) (f:'a -> 'b ft_ref) = f (get a)

let () =
	let ref_a = return 'a' in
	let ref_1 = return 1 in

	print_endline "(* ref_a which is a ft_ref to a char *)";
	print_endline "(* ref_1 which is a ft_ref to 1 int *)";
	print_char '\n';

	print_endline "Test with [print_char (get ref_a)]: ";
	print_char (get ref_a);
	print_char '\n';
	print_endline "Test with [print_int (get ref_1)]: ";
	print_int (get ref_1);
	print_char '\n';

	print_char '\n';
	print_endline "(* set ref_a 'b' *)";
	set ref_a 'b';
	print_endline "(* set ref_1 2 *)";
	set ref_1 2;
	print_char '\n';

	print_endline "Test with [print_char (get ref_a)]: ";
	print_char (get ref_a);
	print_char '\n';
	print_endline "Test with [print_int (get ref_1)]: ";
	print_int (get ref_1);
	print_char '\n';

	let c2i (a:'a) = return (int_of_char a) in
	print_endline "Test with [print_int (get (bind ref_a int_of_char))]: ";
	print_int (get (bind ref_a c2i));
	print_char '\n';


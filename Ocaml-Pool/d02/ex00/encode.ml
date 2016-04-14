let encode lst =
	let rec lst2tuples lst = match lst with
		| [] -> []
		| head::tail -> (1, head) :: lst2tuples tail in
	let sameTuplesChar (n1,c1) (n2,c2) = if (c1 = c2) then true else false in
	let incTuple (n,c) = (n+1,c) in
	let rec concatTuples lst =
		match lst with
			| [] -> []
			| head::mid::tail when sameTuplesChar head mid -> concatTuples ((incTuple head)::tail)
			| head::tail -> head :: concatTuples tail
	in
	concatTuples(lst2tuples lst)

let rec dump_tuple_list lst =
	let print_tuple (nb,c) = print_int nb ; print_char c in
	match lst with
		| head::tail -> print_tuple head ; dump_tuple_list tail
		| [] -> print_char '\n'

let () =
	print_endline "Test with []: ";
	dump_tuple_list (encode []);
	print_endline "Test with ['a']: ";
	dump_tuple_list (encode ['a']);
	print_endline "Test with ['a','a','a','a','a','a','a','a']: ";
	dump_tuple_list (encode ['a';'a';'a';'a';'a';'a';'a';'a']);
 	print_endline "Test with ['a','a','a','b','b','b']: ";
	dump_tuple_list (encode ['a';'a';'a';'b';'b';'b']);
	print_endline "Test with ['a','b','c','d','e']: ";
	dump_tuple_list (encode ['a';'b';'c';'d';'e'])

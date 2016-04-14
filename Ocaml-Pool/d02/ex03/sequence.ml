let sequence n =
	let rec loop lst n =

		let rec lst2string lst str = match lst with
			| [] -> str
			| head::tail -> lst2string tail (str ^ (string_of_int head))
		in

		let rec tuples2lst lst = match lst with
			| [] -> []
			| (nb,c)::tail -> nb :: c :: tuples2lst tail in

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
		let nextLst = tuples2lst (concatTuples (lst2tuples lst)) in
		if (n > 0) then loop nextLst (n-1) else lst2string nextLst ""
	in
	match n with
		| x when x == 1 -> "1"
		| x when x > 1 -> loop [1] (n-2)
		| _ -> ""

let () =
	print_endline "Test with [-1]:";
	print_endline (sequence (-1));
	print_endline "Test with [0]:";
	print_endline (sequence 0);
	print_endline "Test with [1]:";
	print_endline (sequence 1);
	print_endline "Test with [2]:";
	print_endline (sequence 2);
	print_endline "Test with [3]:";
	print_endline (sequence 3);
	print_endline "Test with [4]:";
	print_endline (sequence 4);
	print_endline "Test with [5]:";
	print_endline (sequence 5);
	print_endline "Test with [6]:";
	print_endline (sequence 6);
	print_endline "Test with [7]:";
	print_endline (sequence 7)

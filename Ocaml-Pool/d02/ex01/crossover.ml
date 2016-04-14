let crossover lst1 lst2 =
	let rec isInLst2 toSearchLst lst2 = match lst2 with
		| head::tail when head = toSearchLst -> true
		| head::tail when head <> toSearchLst -> isInLst2 toSearchLst tail
		| _::_ | [] -> false
	in
	let rec loop lst1 lst2 = match lst1 with
		| head::tail when isInLst2 head lst2 && isInLst2 head tail == false -> head :: (loop tail lst2)
		| head::tail -> loop tail lst2
		| [] -> []
	in
	loop lst1 lst2

let rec dump_int_list lst = match lst with | head::tail -> print_int head ; dump_int_list tail | [] -> print_char '\n'
let rec dump_char_list lst = match lst with | head::tail -> print_char head ; dump_char_list tail | [] -> print_char '\n'
let () =
	print_endline "Test with [][]: ";
	dump_int_list (crossover [] []);
	print_endline "Test with [1][1]: ";
	dump_int_list (crossover [1][1]);
	print_endline "Test with ['a']['b']: ";
	dump_char_list (crossover ['a']['b']);
	print_endline "Test with [5,4,3,2,1][2,4,4,4,4]: ";
	dump_int_list (crossover [5;4;3;2;1][2;4;4;4;4]);
	print_endline "Test with ['t','o','t','o']['t','a','t','a']: ";
	dump_char_list (crossover ['t';'o';'t';'o']['t';'a';'t';'a']);

type phosphate = string

type deoxyribose = string

type nucleobase = A | T | C | G | None

type nucleotide = {phosphate:phosphate;deoxyribose:deoxyribose;nucleobase:nucleobase}

let generate_nucleotide nucleobaseType = match nucleobaseType with
	| 'A' -> { phosphate = "phosphate" ; deoxyribose = "deoxyribose" ; nucleobase = A }
	| 'T' -> { phosphate = "phosphate" ; deoxyribose = "deoxyribose" ; nucleobase = T }
	| 'C' -> { phosphate = "phosphate" ; deoxyribose = "deoxyribose" ; nucleobase = C }
	| 'G' -> { phosphate = "phosphate" ; deoxyribose = "deoxyribose" ; nucleobase = G }
	| _ -> { phosphate = "phosphate" ; deoxyribose = "deoxyribose" ; nucleobase = None }

type helix = nucleotide list

let generate_helix n =
	let rec loop (lst:helix) n =
		let getRandomNucleotide = match (Random.int 4) with
			| 0 -> generate_nucleotide 'A'
			| 1 -> generate_nucleotide 'T'
			| 2 -> generate_nucleotide 'C'
			| 3 -> generate_nucleotide 'G'
			| _ -> generate_nucleotide 'N'
		in
		match n with
			| y when y > 0 -> loop (getRandomNucleotide :: lst) (n-1)
			| _ -> lst
	in
	loop [] n

let helix_to_string (lst:helix) =
	let getNucleobaseString nucleotide = match nucleotide.nucleobase with
		| A -> "A"
		| T -> "T"
		| C -> "C"
		| G -> "G"
		| _ -> "None"
	in
	let rec loop lst str = match lst with
		| [] -> str
		| head::mid::tail -> loop (mid::tail) (str ^ (getNucleobaseString head) ^ ", ")
		| head::tail -> loop tail (str ^ (getNucleobaseString head))
	in
	loop lst ""

let complementary_helix (lst:helix) =
	let getNucleotidePair nucleotide (lst2:helix) = match nucleotide.nucleobase with
		| A -> generate_nucleotide 'T' :: lst2
		| T -> generate_nucleotide 'A' :: lst2
		| C -> generate_nucleotide 'G' :: lst2
		| G -> generate_nucleotide 'C' :: lst2
		| _ -> generate_nucleotide 'N' :: lst2
	in
	let rec loop (src:helix) (dst:helix) = match src with
		| [] -> dst
		| head::tail -> loop tail (dst @ (getNucleotidePair head []))
	in
	loop lst []

let () =
	Random.self_init ();

	print_endline "Test with ['0']:";
	let helix0 = generate_helix 0 in
	print_endline (helix_to_string helix0);
	print_endline (helix_to_string (complementary_helix helix0));

	print_endline "Test with ['1']:";
	let helix1 = generate_helix 1 in
	print_endline (helix_to_string helix1);
	print_endline (helix_to_string (complementary_helix helix1));

	print_endline "Test with ['5']:";
	let helix5 = generate_helix 5 in
	print_endline (helix_to_string helix5);
	print_endline (helix_to_string (complementary_helix helix5));

	print_endline "Test with ['20']:";
	let helix20 = generate_helix 20 in
	print_endline (helix_to_string helix20);
	print_endline (helix_to_string (complementary_helix helix20))

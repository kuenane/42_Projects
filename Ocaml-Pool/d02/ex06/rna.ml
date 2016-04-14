type phosphate = string

type deoxyribose = string

type nucleobase = A | T | C | G | U | None

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
		| U -> "U"
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

type rna = nucleobase list

let generate_rna (hlx:helix) =
	let rec convertT2U_nucleobaseList (hlst:helix) (rlst:rna) =	
		let getNucleobaseConverted nucleotide = match nucleotide.nucleobase with
			| T -> U :: []
			| _ -> nucleotide.nucleobase :: []
		in
		match hlst with
			| head::tail -> convertT2U_nucleobaseList tail (rlst @ (getNucleobaseConverted head)) 
			| [] -> rlst
	in
	convertT2U_nucleobaseList (complementary_helix hlx) []

let rna_to_string (lst:rna) =
	let getNucleobaseString nucleobase = match nucleobase with
		| A -> "A"
		| T -> "T"
		| C -> "C"
		| G -> "G"
		| U -> "U"
		| _ -> "None"
	in
	let rec loop lst str = match lst with
		| [] -> str
		| head::mid::tail -> loop (mid::tail) (str ^ (getNucleobaseString head) ^ ", ")
		| head::tail -> loop tail (str ^ (getNucleobaseString head))
	in
    loop lst ""

let () =
	Random.self_init ();

	print_endline "Test with ['0']:";
	let helix0 = complementary_helix (generate_helix 0) in
	print_endline (helix_to_string helix0);
	print_endline (rna_to_string (generate_rna helix0));

	print_endline "Test with ['1']:";
	let helix1 = complementary_helix (generate_helix 1) in
	print_endline (helix_to_string helix1);
	print_endline (rna_to_string (generate_rna helix1));

	print_endline "Test with ['5']:";
	let helix5 = complementary_helix (generate_helix 5) in
	print_endline (helix_to_string helix5);
	print_endline (rna_to_string (generate_rna helix5));

	print_endline "Test with ['20']:";
	let helix20 = complementary_helix (generate_helix 20) in
	print_endline (helix_to_string helix20);
	print_endline (rna_to_string (generate_rna helix20))

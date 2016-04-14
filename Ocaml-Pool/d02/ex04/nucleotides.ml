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

let () =
	let print_nucleotide_type nucleotide = match nucleotide.nucleobase with
		| A -> print_endline "A"
		| T -> print_endline "T"
		| C -> print_endline "C"
		| G -> print_endline "G"
		| _ -> print_endline "None"
	in
	print_endline "Test with ['A']:";
	print_nucleotide_type (generate_nucleotide 'A');
	print_endline "Test with ['T']:";
	print_nucleotide_type (generate_nucleotide 'T');
	print_endline "Test with ['C']:";
	print_nucleotide_type (generate_nucleotide 'C');
	print_endline "Test with ['G']:";
	print_nucleotide_type (generate_nucleotide 'G');
	print_endline "Test with ['N']:";
	print_nucleotide_type (generate_nucleotide 'N')

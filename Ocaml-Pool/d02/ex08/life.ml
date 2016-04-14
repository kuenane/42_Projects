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

let generate_bases_triplets (lst:rna) =
	let rec loop (src:rna) = match src with
		| head::scnd::thd::tail -> (head, scnd, thd) :: loop tail
		| _ -> []
	in
	loop lst

let tripletsList_to_string (lst) =
	let getNucleobaseString nucleobase = match nucleobase with
		| A -> "A"
		| T -> "T"
		| C -> "C"
		| G -> "G"
		| U -> "U"
		| _ -> "None"
	in
	let getNucleobaseStringFromTuple (x,y,z) = (getNucleobaseString x)^(getNucleobaseString y)^(getNucleobaseString z) in
	let rec loop lst str = match lst with
		| [] -> str
		| head::mid::tail -> loop (mid::tail) (str ^ (getNucleobaseStringFromTuple head) ^ ", ")
		| head::tail -> loop tail (str ^ (getNucleobaseStringFromTuple head))
	in
    loop lst ""

type aminoacid = Stop | Ala | Arg | Asn | Asp | Cys | Gln | Glu | Gly | His | Ile | Leu | Lys | Met | Phe | Pro | Ser | Thr | Trp | Tyr | Val

type protein = aminoacid list

let decode_arn (r:rna) =
	let getAminoacidFromTriplet (x,y,z) = match (x,y,z) with
		| G, C, A | G, C, C | G, C, G | G, C, U -> Ala
		| A, G, A | A, G, G | C, G, A | C, G, C | C, G, G | C, G, U	-> Arg
		| A, A, C | A, A, U -> Asn
		| G, A, C | G, A, U -> Asp
		| U, G, C | U, G, U -> Cys
		| C, A, A | C, A, G -> Gln
		| G, A, A | G, A, G -> Glu
		| G, G, A | G, G, C | G, G, G | G, G, U -> Gly
		| C, A, C | C, A, U -> His
		| A, U, A | A, U, C | A, U, U -> Ile
		| C, U, A | C, U, C | C, U, G | C, U, U | U, U, A | U, U, G	-> Leu
		| A, A, A | A, A, G -> Lys
		| A, U, G -> Met
		| U, U, C | U, U, U -> Phe
		| C, C, C | C, C, A | C, C, G | C, C, U -> Pro
		| U, C, A | U, C, C | U, C, G | U, C, U | A, G, U | A, G, C	-> Ser
		| A, C, A | A, C, C | A, C, G | A, C, U -> Thr
		| U, G, G -> Trp
		| U, A, C | U, A, U -> Tyr
		| G, U, A | G, U, C | G, U, G | G, U, U -> Val
		| U, A, A | U, A, G | U, G, A | _ -> Stop
	in
	let rec loop src = match src with
		| head::tail when (getAminoacidFromTriplet head) == Stop -> (getAminoacidFromTriplet head) :: []
		| head::tail -> (getAminoacidFromTriplet head) :: loop tail
		| _ -> []
	in
	loop (generate_bases_triplets r)


let string_of_protein (lst:protein) =
	let getStringFromAminoacid aminoacid = match aminoacid with
		| Ala -> "Ala"
		| Arg -> "Arg"
		| Asn -> "Asn"
		| Asp -> "Asp" 
		| Cys -> "Cys" 
		| Gln -> "Gln" 
		| Glu -> "Glu" 
		| Gly -> "Gly" 
		| His -> "His" 
		| Ile -> "Ile" 
		| Leu -> "Leu" 
		| Lys -> "Lys" 
		| Met -> "Met" 
		| Phe -> "Phe" 
		| Pro -> "Pro" 
		| Ser -> "Ser" 
		| Thr -> "Thr" 
		| Trp -> "Trp" 
		| Tyr -> "Tyr" 
		| Val -> "Val" 
		| _ -> "Stop"
	in
	let rec loop lst str = match lst with
		| [] -> str
		| head::mid::tail -> loop (mid::tail) (str ^ (getStringFromAminoacid head) ^ ", ")
		| head::tail -> loop tail (str ^ (getStringFromAminoacid head))
	in
    loop lst ""	

let helix2protein str =
	let string2helix str =
		let rec loop str n dst = match n with
			| n when n < 0 -> dst
			| _	-> loop str (n - 1) (generate_nucleotide (String.get str n) :: dst)
		in
		loop str ((String.length str) - 1) []
	in

	print_string "Helix creation = ";
	let hlx = string2helix str in
	print_endline (helix_to_string hlx);

	print_string "Complementary helix = ";
	let comp_hlx = complementary_helix hlx in
	print_endline (helix_to_string comp_hlx);

	print_string "Rna = ";
	let rna = generate_rna hlx in
	print_endline (rna_to_string rna);

	print_string "Triplets list = ";
	let tripletList = generate_bases_triplets rna in
	print_endline (tripletsList_to_string tripletList);

	print_string "Protein = ";
	print_endline (string_of_protein (decode_arn rna))

let () =
	Random.self_init ();
	print_endline "Test with []:";
	helix2protein "";
	print_char '\n';
	print_endline "Test with ['ATCG']:";
	helix2protein "ATCG";
	print_char '\n';
	print_endline "Test with ['TCGTCAGTACTAGCATGCATATCGAGTCGTACGTAGTATATATACGCGGCGCATCAGTGCATCAGTCGATCTAGCTAGCATGCATCTACTGAGTCATCATCG']:";
	helix2protein "TCAGTACTAGCATGCATATCGAGTCGTACGTAGTATATACGCGGCGCATCAGTGCATCAGTCGATCTAGCTAGCATGCATCTACTGAGTCATCATCG"

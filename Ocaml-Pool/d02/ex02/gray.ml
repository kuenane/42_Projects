(*
	On passe d'un nombre au suivant en changeant un bit:
		- Règle 1: le dernier si le nombre de " 1 " est pair, et
	   	- Règle 2: celui à gauche du " 1 " le plus à droite, sinon.

	source: http://villemin.gerard.free.fr/Wwwgvmm/Numerati/CodeGray.htm
*)

let printGraySequence n = 

	let isNbOf1Even str =
		let rec loop str pos count =
			if (pos = String.length str) then
				if (count mod 2 == 0) then true else false
			else if (String.get str pos = '1') then 
				loop str (pos+1) (count+1)
			else
				loop str (pos+1) (count)
		in
		loop str 0 0 in

	let rec buildAndPrintSequence lastElem =
		let invertSpecifiedElem str pos = match str with
			| y when String.get y pos == '0' -> Bytes.set str pos '1' ; str
			| _ -> Bytes.set str pos '0' ; str
		in
		print_string lastElem;
		if (isNbOf1Even lastElem == true) then
			let newElem = invertSpecifiedElem lastElem ((String.length lastElem)-1) in
			print_char ' ';
			buildAndPrintSequence (newElem)
		else
			let last1pos = String.rindex lastElem '1' in
			if (last1pos == 0) then
				print_char '\n'
			else
				let newElem2 = invertSpecifiedElem lastElem (last1pos - 1) in
				print_char ' ';
				buildAndPrintSequence (newElem2)
	in

	if (n > 0) then buildAndPrintSequence (String.make n '0') else print_char '\n'

let () =
	print_endline "Test with [-1]:";
	printGraySequence (-1);
	print_endline "Test with [0]:";
	printGraySequence 0;
	print_endline "Test with [1]:";
	printGraySequence 1;
	print_endline "Test with [2]:";
	printGraySequence 2;
	print_endline "Test with [3]:";
	printGraySequence 3;
	print_endline "Test with [5]:";
	printGraySequence 5

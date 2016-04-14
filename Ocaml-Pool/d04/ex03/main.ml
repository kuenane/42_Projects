let () =
	let rec print_list lst = match lst with
		| head::mid::tail -> print_string head ; print_char ' ' ; print_list (mid::tail)
		| head::tail -> print_string head ; print_list tail
		| [] -> print_char '\n'
	in
	let ndeck = Deck.newDeck in
	print_endline "let ndeck = Deck.newDeck";
	print_char '\n';
	print_endline "Test with [print_list (toStringList ndeck)]: ";
	print_list (Deck.toStringList ndeck);
	print_char '\n';
	print_endline "Test with [print_list (toStringListVerbose ndeck)]: ";
	print_list (Deck.toStringListVerbose ndeck);
	print_char '\n';
	let getFirstCard (c,d) = c in
	print_endline "Test with [toStringVerbose (Deck.drawCard ndeck)]: ";
	print_endline (Deck.Card.toStringVerbose (getFirstCard (Deck.drawCard ndeck)))

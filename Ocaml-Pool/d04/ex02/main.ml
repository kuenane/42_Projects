let () =
	let rec print_verbose lst = match lst with | head::tail -> print_endline (Card.toStringVerbose head); print_verbose tail | _ -> () in
	print_endline "Test with [print_verbose Card.allSpades Card.all]: ";
	print_verbose Card.allSpades;
	print_char '\n';

	print_endline "Test with [Value.toString (getValue (newCard T2 Spade))]: ";
	print_endline (Card.Value.toString (Card.getValue (Card.newCard Card.Value.T2 Card.Color.Spade)));
	print_char '\n';

	print_endline "Test with [Color.toString (getColor (newCard T2 Spade))]: ";
	print_endline (Card.Color.toString (Card.getColor (Card.newCard Card.Value.T2 Card.Color.Spade)));
	print_char '\n';

	print_endline "Test with [Color.toString (getColor (newCard T2 Spade))]: ";
	print_endline (Card.toStringVerbose (Card.max (Card.newCard (Card.Value.King) (Card.Color.Diamond)) (Card.newCard (Card.Value.Jack) (Card.Color.Club))));
	print_char '\n';

	print_endline "Test with [Card.toStringVerbose (Card.min (Card.newCard (Card.Value.King) (Card.Color.Diamond)) (Card.newCard (Card.Value.Jack) (Card.Color.Club)))]: ";
	print_endline (Card.toStringVerbose (Card.min (Card.newCard (Card.Value.King) (Card.Color.Diamond)) (Card.newCard (Card.Value.Jack) (Card.Color.Club))));
	print_char '\n';

	print_endline "Test with [Card.toStringVerbose (Card.best Card.allSpades)]: ";
	print_endline (Card.toStringVerbose (Card.best Card.allSpades));

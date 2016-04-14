let () =
	print_endline "Test with [toto = new People.people 'Toto']:" ;
	let toto = new People.people "Toto" in
	print_char '\n';

	print_endline "Test with [toto#to_string]:";
	print_endline toto#to_string;
	print_char '\n';

	print_endline "Test with [toto#talk]:";
	toto#talk;
	print_char '\n';

	print_endline "Test with [toto#die]:";
	toto#die

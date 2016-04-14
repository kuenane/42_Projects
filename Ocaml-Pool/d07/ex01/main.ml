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
	toto#die;

	print_char '\n';
	print_endline "----------------------";
	print_char '\n';

	print_endline "Test with [titi = new Doctor.doctor \"Titi\" 42 toto]:" ;
	let titi = new Doctor.doctor "Titi" 42 toto in
	print_char '\n';
	print_endline "Test with [titi#to_string]:";
	print_endline titi#to_string;
	print_char '\n';
	print_endline "Test with [titi#talk]:";
	titi#talk;
	print_char '\n';
	print_endline "Test with [titi#travel_in_time 1 2]:";
	titi#travel_in_time 1 10;
	print_char '\n';
	print_endline "Test with [titi#use_sonic_screwdriver]:";
	titi#use_sonic_screwdriver;

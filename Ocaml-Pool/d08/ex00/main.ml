let () =
	let hydrogen = new Atom.hydrogen in
	let carbon = new Atom.carbon in
	let oxygen = new Atom.oxygen in
	let aluminum = new Atom.aluminum in
	let lithium = new Atom.lithium in
	let silicon = new Atom.silicon in
	let calcium = new Atom.calcium in
	let zinc = new Atom.zinc in
	let platinum = new Atom.platinum in
	let radium = new Atom.radium in
	let plutonium = new Atom.plutonium in

	print_endline "Test with [hydrogen#to_string]:";
	print_endline hydrogen#to_string;
	print_char '\n';

	print_endline "Test with [carbon#to_string]:";
	print_endline carbon#to_string;
	print_char '\n';

	print_endline "Test with [oxygen#to_string]:";
	print_endline oxygen#to_string;
	print_char '\n';

	print_endline "Test with [aluminum#to_string]:";
	print_endline aluminum#to_string;
	print_char '\n';

	print_endline "Test with [lithium#to_string]:";
	print_endline lithium#to_string;
	print_char '\n';

	print_endline "Test with [silicon#to_string]:";
	print_endline silicon#to_string;
	print_char '\n';

	print_endline "Test with [calcium#to_string]:";
	print_endline calcium#to_string;
	print_char '\n';

	print_endline "Test with [zinc#to_string]:";
	print_endline zinc#to_string;
	print_char '\n';
	
	print_endline "Test with [platinum#to_string]:";
	print_endline platinum#to_string;
	print_char '\n';
	
	print_endline "Test with [radium#to_string]:";
	print_endline radium#to_string;
	print_char '\n';
	
	print_endline "Test with [plutonium#to_string]:";
	print_endline plutonium#to_string;
	print_char '\n';


	print_endline "Test with [plutonium#equals carbon]:";
	if (plutonium#equals carbon == true) then print_endline "true" else print_endline "false";
	print_char '\n';

	print_endline "Test with [plutonium#equals plutonium]:";
	if (plutonium#equals plutonium == true) then print_endline "true" else print_endline "false"

let () =
	let water = new Molecule.water in
	let carbon_dioxyde = new Molecule.carbon_dioxyde in
	let dioxygen = new Molecule.dioxygen in
	let acetone = new Molecule.acetone in
	let ethanol = new Molecule.ethanol in
	let isobutane = new Molecule.isobutane in

	print_endline "Test with [water#to_string]:";
	print_endline water#to_string;
	print_char '\n';

	print_endline "Test with [carbon_dioxyde#to_string]:";
	print_endline carbon_dioxyde#to_string;
	print_char '\n';
	
	print_endline "Test with [dioxygen#to_string]:";
	print_endline dioxygen#to_string;
	print_char '\n';
	
	print_endline "Test with [acetone#to_string]:";
	print_endline acetone#to_string;
	print_char '\n';
	
	print_endline "Test with [ethanol#to_string]:";
	print_endline ethanol#to_string;
	print_char '\n';
	
	print_endline "Test with [isobutane#to_string]:";
	print_endline isobutane#to_string;
	print_char '\n';

	print_endline "Test with [water#equals acetone]:";
	if (water#equals acetone = true) then print_endline "true" else print_endline "false";
	print_char '\n';
	
	print_endline "Test with [water#equals water]:";
	if (water#equals water = true) then print_endline "true" else print_endline "false"

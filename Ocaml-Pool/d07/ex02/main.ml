let () =
	Random.self_init ();
	let p = new People.people "People" in
	p#talk;
	print_endline ("Whiiii... " ^ (p#to_string));
	print_endline "Now die";
	let d = new Doctor.doctor "Doctor" 42 p in
	d#talk;
	print_endline (d#to_string);
	d#travel_in_time 2058 2016;
	d#use_sonic_screwdriver;
	let dalek = new Dalek.dalek in
	p#talk;
	print_endline (dalek#to_string);
	ignore (dalek#exterminate p);
	dalek#talk;
	dalek#die

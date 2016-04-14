class galifrey =
object
    val peoples_army = ([]:People.people list)
    val doctors_army = ([]:Doctor.doctor list)
    val dalek_army = ([]:Dalek.dalek list)
    method do_time_war = 
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
		dalek#die;
		let army = new Army.army in
		let army = army#add (new Dalek.dalek) in
		let army = army#add (new Dalek.dalek) in
		let army = army#add (new Dalek.dalek) in
		let army = army#add (new Dalek.dalek) in
		let army = army#add (new Dalek.dalek) in
		let army = army#add (new Dalek.dalek) in
		let army = army#add (new Dalek.dalek) in
		let army = army#add (new Dalek.dalek) in
		print_string "army size = ";
		print_int army#size;
		print_char '\n';
		p#talk;
		print_endline (dalek#to_string);
		ignore (dalek#exterminate p);
		dalek#talk;
		let army = army#delete in
		let army = army#delete in
		let army = army#delete in
		let army = army#delete in
		let army = army#delete in
		let army = army#delete in
		let army = army#delete in
		print_string "army size = ";
		print_int army#size;
		print_char '\n';
		print_endline "One and only one fighter stay alive, WOW"
end

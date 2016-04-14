let () =
	print_endline "creation of 3 peoples...";
	let people1 = new People.people "People1" in
	let people2 = new People.people "People2" in
	let people3 = new People.people "People3" in
	print_char '\n';

	print_endline "creation of 3 doctors...";
	let doctor1 = new Doctor.doctor "Doctor1" 42 people1 in
	let doctor2 = new Doctor.doctor "Doctor2" 42 people2 in
	let doctor3 = new Doctor.doctor "Doctor3" 42 people3 in
	print_char '\n';

	print_endline "creation of 3 daleks...";
	let dalek1 = new Dalek.dalek in
	let dalek2 = new Dalek.dalek in
	let dalek3 = new Dalek.dalek in
	print_char '\n';

	print_endline "creation of a people army...";
	let army1 = new Army.army in
	let army1 = army1#add people1 in
	let army1 = army1#add people2 in
	let army1 = army1#add people3 in
	print_char '\n';

	print_endline "creation of a doctor army...";
	let army2 = new Army.army in
	let army2 = army2#add doctor1 in
	let army2 = army2#add doctor2 in
	let army2 = army2#add doctor3 in
	print_char '\n';

	print_endline "creation of a dalek army...";
	let army3 = new Army.army in
	let army3 = army3#add dalek1 in
	let army3 = army3#add dalek2 in
	let army3 = army3#add dalek3 in
	print_char '\n';

	print_string "peoples army size = ";
	print_int army1#size;
	print_char '\n';

	print_string "doctors army size = ";
	print_int army2#size;
	print_char '\n';

	print_string "daleks army size = ";
	print_int army3#size;
	print_char '\n';
	print_char '\n';

	print_endline "destruction of a people army...";
	let army1 = new Army.army in
	let army1 = army1#delete in
	let army1 = army1#delete in
	let army1 = army1#delete in
	print_char '\n';

	print_endline "destruction of a doctor army...";
	let army2 = new Army.army in
	let army2 = army2#delete in
	let army2 = army2#delete in
	let army2 = army2#delete in
	print_char '\n';

	print_endline "destruction of a dalek army...";
	let army3 = new Army.army in
	let army3 = army3#delete in
	let army3 = army3#delete in
	let army3 = army3#delete in
	print_char '\n';

	print_string "peoples army size = ";
	print_int army1#size;
	print_char '\n';

	print_string "doctors army size = ";
	print_int army2#size;
	print_char '\n';

	print_string "daleks army size = ";
	print_int army3#size;
	print_char '\n'

let () =
	let arr = Array.make 8 "" in
	arr.(0) <- "C'est un gars qui rentre dans un café et plouf !";
	arr.(1) <- "C'est la blague de la cravate : elle est longue et plate.";
	arr.(2) <- "Qu'est-ce que '1111111111111111111' ??? Un troupeau de 1";
	arr.(3) <- "Pourquoi un escargot traverse la route quand il pleut ? Pour aller de l'autre côté...";
	arr.(4) <- "C'est l'histoire d'un schtroumpf qui tombe, et qui se fait un bleu.";
	arr.(5) <- "Connaissez-vous la blague de la chaise? Elle est pliante.";
	arr.(6) <- "Que fait une patate qui a la diarrhée ? De la purée";
	arr.(7) <- "Tu connais la blague à deux balles? Pan Pan.";
	Random.self_init ();
	print_endline arr.(Random.int 8)

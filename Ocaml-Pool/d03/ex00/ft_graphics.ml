type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y s =
	let s2 = (s/2) in
	let leftx = x - s2 in
	let rightx = x + s2 in
	let topy = y - s2 in
	let boty = y + s2 in
	Graphics.moveto leftx topy;
	Graphics.lineto rightx topy;
	Graphics.lineto rightx boty;
	Graphics.lineto leftx boty;
	Graphics.lineto leftx topy

let draw_str x y str padx pady = Graphics.moveto (x-padx) (y-pady) ; Graphics.draw_string str

let draw_square_str x y s str padx pady = draw_square x y s ; draw_str x y str padx pady

let draw_line (srcx, srcy) (dstx, dsty) = Graphics.moveto srcx srcy ; Graphics.lineto dstx dsty

let draw_tree_node node = match node with
	| Nil				-> draw_square_str 600 150 50 "Nil" 8 4
	| Node (str, _, _)	->
		draw_square_str 125 150 50 str 12 6;
		draw_square_str 275 200 50 "Nil" 8 4;
		draw_square_str 275 100 50 "Nil" 8 4;
		draw_line (150,150) (250,200);
		draw_line (150,150) (250,100)

let () =
   	Graphics.open_graph " 800x300";
   	draw_line (400,0) (400,300);

	draw_str 200 10 "Node (\"Toto\", Nil, Nil)" 70 0;
   	draw_tree_node (Node ("Toto", Nil, Nil));

	draw_str 600 10 "Nil" 5 0;
   	draw_tree_node Nil;

	(* JUST FOR TESTS *) ignore(Graphics.read_key ());

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

let draw_line (srcx, srcy) (dstx, dsty) = Graphics.moveto srcx srcy ; Graphics.lineto dstx dsty

let rec size tree = match tree with
	| Node (_,Nil,Nil) -> 1
	| Node (_,n1,Nil) -> 1 + (size n1)
	| Node (_,Nil,n2) -> 1 + (size n2)
	| Node (_,n1,n2) -> 1 + (size n1) + (size n2)
	| Nil -> 0

let rec height tree = match tree with
	| Node (_,Nil,Nil) -> 1
	| Node (_,n1,Nil) -> 1 + (height n1)
	| Node (_,Nil,n2) -> 1 + (height n2)
	| Node (_,n1,n2) -> 1 + (max (height n1) (height n2))
	| Nil -> 0

let draw_tree tree =
	let x_pad = 150 in
	let sqr_size = 50 in
	let half_sqr_size = sqr_size / 2 in
	let rec loop tree x y =
		let height_y = ((height tree) - 1) * sqr_size in
		draw_square x y sqr_size;
		match tree with
		| Node (str, n1, n2)	->
			draw_line (x + half_sqr_size, y) (x + x_pad - half_sqr_size, y + height_y);
			draw_line (x + half_sqr_size, y) (x + x_pad - half_sqr_size, y - height_y);
			draw_str x y str 12 6;
			loop n1 (x + x_pad) (y + height_y);
			loop n2 (x + x_pad) (y - height_y)
		| Nil				-> draw_str x y "Nil" 8 4
	in
	loop tree 50 300

let () =
	let tree = 
		Node ("Lvl0",
			(Node ("Lvl1",
				Nil,
				(Node ("Lvl2", Nil, Nil))
			)),
			(Node ("Lvl1",
				(Node ("Lvl2",
					(Node ("Lvl3", Nil, Nil)),
					(Node ("Lvl3", Nil, Nil))
				)),
				Nil
			))
		)
	in
	let tree_size_str = "Size = " ^ (string_of_int (size tree)) in
	let tree_height_str = "Height = " ^ (string_of_int (height tree)) in

   	Graphics.open_graph " 700x550";
   	draw_str 10 30 tree_size_str 0 0;
   	draw_str 10 10 tree_height_str 0 0;
   	draw_tree (tree);
	ignore(Graphics.read_key ());

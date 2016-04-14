(* http://www.cse.yorku.ca/~oz/hash.html *)
let lose_lose_hash str =
	let rec loop cur acc len = match cur with
		| x when x = len -> acc
		| _ -> loop (cur + 1) (int_of_char (String.get str cur)) len
	in
	loop 0 0 (String.length str)

module StringHashtbl = Hashtbl.Make
(
	struct
		type t = string
		let equal = (=)
		let hash = lose_lose_hash
	end
)

let () =
	let ht = StringHashtbl.create 5 in
	let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
	let pairs = List.map (fun s -> (s, String.length s)) values in
	List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
	StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht

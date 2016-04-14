let need2rotate k = match (int_of_char k) with
	| x when x >= 65 && x <= 90 -> true
	| x when x >= 97 && x <= 122 -> true
	| _ -> false

let caesar n str =
	let rec rot_int y i =
		if (i > 0) then
			if (y == 122 || y == 90) then
				rot_int (y-25) (i-1)
			else
				rot_int (y+1) (i-1)
		else
			char_of_int (y)
	in
	let rot_char c =
		if (need2rotate c) then
			rot_int (int_of_char c) n
		else
			c
	in
	String.map rot_char str

let rot42 str = caesar 42 str

let xor key str =
	let xor_char key c = char_of_int ((int_of_char c) lxor key) in
	String.map (xor_char key) str

let rec ft_crypt (str:string) f = match f with
	| head::tail -> ft_crypt (head str) tail
	| [] -> str

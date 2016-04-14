let uncaesar n str =
	let rec unrot_int y i =
		if (i > 0) then
			if (y == 97 || y == 65) then
				unrot_int (y+25) (i-1)
			else
				unrot_int (y-1) (i-1)
		else
			char_of_int (y)
	in
	let unrot_char c =
		if (Cipher.need2rotate c) then
			unrot_int (int_of_char c) n
		else
			c
	in
	String.map unrot_char str

let unrot42 str = uncaesar 42 str

let rec ft_uncrypt (str:string) f = match f with
	| head::tail -> head (ft_uncrypt str tail)
	| [] -> str


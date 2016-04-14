module type FIXED =
sig
	type t
	val of_float : float -> t
	val of_int : int -> t
	val to_float : t -> float 
	val to_int :t -> int
	val to_string : t -> string
	val zero : t
	val one : t
	val succ : t -> t
	val pred : t -> t
	val min : t -> t -> t
	val max : t -> t -> t
	val gth : t -> t -> bool
	val lth : t -> t -> bool
	val gte : t -> t -> bool
	val lte : t -> t -> bool
	val eqp : t -> t -> bool
	val eqs : t -> t -> bool
	val add : t -> t -> t
	val sub : t -> t -> t
	val mul : t -> t -> t
	val div : t -> t -> t
	val foreach : t -> t -> (t -> unit) -> unit
end

(*  *)

module type FRACTIONNAL_BITS =
sig
	val bits : int
end

module type MAKE =
	functor (Fbits:FRACTIONNAL_BITS) -> FIXED

let round t = if (t > 0.) then (t +. 0.5) else t -. 0.5

module Make : MAKE = functor (Fbits:FRACTIONNAL_BITS) ->
struct
	type t = int
	let of_float t = int_of_float (round (t *. (float_of_int (1 lsl Fbits.bits))))
	let of_int t = t * (1 lsl Fbits.bits)
	let to_int t = t / (1 lsl Fbits.bits)
	let to_float t = (float_of_int t) /. (float_of_int (1 lsl Fbits.bits))
	let to_string t = string_of_float (to_float t)
	let zero = 0
	let one = of_int 1
	let succ t = t+1
	let pred t = t-1
	let min t1 t2 = if (t1 < t2) then t1 else t2
	let max t1 t2 = if (t1 > t2) then t1 else t2
	let gth t1 t2 = if (t1 > t2) then true else false
	let lth t1 t2 = if (t1 < t2) then true else false
	let gte t1 t2 = if (t1 >= t2) then true else false
	let lte t1 t2 = if (t1 <= t2) then true else false
	let eqp t1 t2 = if (t1 = t2) then true else false
	let eqs t1 t2 = if (t1 == t2) then true else false
	let add t1 t2 = t1 + t2
	let sub t1 t2 = t1 - t2
	let mul t1 t2 = int_of_float ((float_of_int t1) *. (to_float t2))
	let div t1 t2 = of_float ((to_float t1) /. (to_float t2))

	let foreach t1 t2 f =
		let rec loop t1 =
			if (t1 <= t2) then
			begin
				f t1; loop (t1 + 1)
			end
			else
				()
		and loop_down t1 =
			if (t1 >= t2) then
			begin
				f t1; loop_down (t1 - 1)
			end
			else
				()
		in
		if (t1 > t2) then
			loop_down t1
		else
			loop t1
end

(*  *)

module Fixed4 : FIXED = Make (struct let bits = 4 end)

module Fixed8 : FIXED = Make (struct let bits = 8 end)

let () =
	let x8 = Fixed8.of_float 21.10 in
	let y8 = Fixed8.of_float 21.32 in
	let r8 = Fixed8.add x8 y8 in
	print_endline (Fixed8.to_string r8);
	Fixed4.foreach (Fixed4.zero) (Fixed4.one) (fun f -> print_endline (Fixed4.to_string f));

	print_char '\n';

	print_endline "Test with [Fixed8.to_string x8]:";
	print_endline (Fixed8.to_string x8);

	print_endline "Test with [Fixed8.to_int x8]:";
	print_int (Fixed8.to_int x8);
	print_char '\n';

	print_endline "Test with [Fixed8.to_float x8]:";
	print_float (Fixed8.to_float x8);
	print_char '\n';

	print_endline "Test with [Fixed8.to_int Fixed8.zero]:";
	print_int (Fixed8.to_int Fixed8.zero);
	print_char '\n';

	print_endline "Test with [Fixed8.to_int Fixed8.one]:";
	print_int (Fixed8.to_int Fixed8.one);
	print_char '\n';

	print_endline "Test with [Fixed8.to_int (Fixed8.pred x8)]:";
	print_int (Fixed8.to_int (Fixed8.pred x8));
	print_char '\n';

	let print_bool state = if (state = true) then print_string "true" else print_string "false" in

	print_endline "Test with [print_bool (Fixed8.gth x8 y8)]:";
	print_bool (Fixed8.gth x8 y8);
	print_char '\n';

	print_endline "Test with [print_bool (Fixed8.lth x8 y8)]:";
	print_bool (Fixed8.lth x8 y8);
	print_char '\n';

	print_endline "Test with [print_bool (Fixed8.gte x8 y8)]:";
	print_bool (Fixed8.gte x8 y8);
	print_char '\n';

	print_endline "Test with [print_bool (Fixed8.lte x8 y8)]:";
	print_bool (Fixed8.lte x8 y8);
	print_char '\n';

	print_endline "Test with [print_bool (Fixed8.eqp x8 y8)]:";
	print_bool (Fixed8.eqp x8 y8);
	print_char '\n';

	print_endline "Test with [print_bool (Fixed8.eqs x8 y8)]:";
	print_bool (Fixed8.eqs x8 y8);
	print_char '\n';

 	print_endline "Test with [Fixed8.to_int (Fixed8.add x8 x8)]:";
	print_int (Fixed8.to_int (Fixed8.add x8 x8));
	print_char '\n';

	print_endline "Test with [Fixed8.to_int (Fixed8.sub x8 x8)]:";
	print_int (Fixed8.to_int (Fixed8.sub x8 x8));
	print_char '\n';

	print_endline "Test with [Fixed8.to_int (Fixed8.mul x8 x8)]:";
	print_int (Fixed8.to_int (Fixed8.mul x8 x8));
	print_char '\n';

	print_endline "Test with [Fixed8.to_int (Fixed8.div x8 x8)]:";
	print_int (Fixed8.to_int (Fixed8.div x8 x8));
	print_char '\n';

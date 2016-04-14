let rec atomlist2strlist (src:Atom.atom list) (dst:string list) = match src with
	| [] -> dst
	| head::tail -> atomlist2strlist tail (dst @ [head#symbol])

let sortStringListByAsc (lst:string list) = List.stable_sort String.compare lst

let rec stringList2tuplesList (src:string list) dst = match src with
	| [] -> dst
	| head::tail -> stringList2tuplesList tail (dst @ [(head,1)])

let rec concatTuplesList lst =
	let sameTuplesStr (s1,n1) (s2,n2) = if (s1 = s2) then true else false in
	let incTuple (s,n) = (s,n+1) in
	match lst with
		| [] -> []
		| head::mid::tail when sameTuplesStr head mid -> concatTuplesList ((incTuple head)::tail)
		| head::tail -> head :: concatTuplesList tail

let rec tuplesList2string lst str = match lst with
	| [] -> str
	| (s,n)::tail when (s = "C" || s = "H") -> if (n > 1) then tuplesList2string tail (s ^ string_of_int n  ^ str) else tuplesList2string tail (s^str)
	| (s,n)::tail -> if (n > 1) then tuplesList2string tail (str ^ s ^ string_of_int n) else tuplesList2string tail (str^s)

class virtual molecule (pName:string) (pFormula:Atom.atom list) =
object (self)
	val _name:string = pName
	val _formula:Atom.atom list = pFormula
	method name = _name
	method formula = tuplesList2string (concatTuplesList (stringList2tuplesList (sortStringListByAsc (atomlist2strlist _formula [])) [])) ""
	method to_string = "name=" ^ _name ^ " formula=" ^ self#formula
	method equals (toCompare:molecule) = if (toCompare#to_string = self#to_string) then true else false
end

class water = object inherit molecule "Water" [new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen] end

class carbon_dioxyde = object inherit molecule "Carbon dioxyde" [new Atom.carbon;new Atom.oxygen;new Atom.oxygen] end

class dioxygen = object inherit molecule "Dioxygen" [new Atom.oxygen;new Atom.oxygen] end

class acetone = object inherit molecule "acetone" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.oxygen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end

class ethanol = object inherit molecule "ethanol" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;new Atom.hydrogen] end

class isobutane = object inherit molecule "isobutane" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end


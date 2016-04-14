class virtual atom (pName:string) (pSymbol:string) (pAtomic_number:int) =
object
	val _name:string = pName
	val _symbol:string = pSymbol
	val _atomic_number:int = pAtomic_number
	method name = _name
	method symbol = _symbol
	method atomic_number = _atomic_number
	method to_string = "name=" ^ _name ^ " symbol=" ^ _symbol ^ " atomic_number=" ^ (string_of_int _atomic_number)
	method equals (toCompare:atom) = if (toCompare#name = _name && toCompare#symbol = _symbol && toCompare#atomic_number = _atomic_number) then true else false
end

class hydrogen = object inherit atom "Hydrogen" "H" 1 end
class carbon = object inherit atom "Carbon" "C" 6 end
class oxygen = object inherit atom "Oxygen" "O" 8 end
class aluminum = object inherit atom "Aluminum" "Al" 13 end
class lithium = object inherit atom "Lithium" "Li" 3 end
class silicon = object inherit atom "Silicon" "Si" 14 end
class calcium = object inherit atom "Calcium" "Ca" 20 end
class zinc = object inherit atom "Zinc" "Zn" 30 end
class platinum = object inherit atom "Platinum" "Pt" 78 end
class radium = object inherit atom "Radium" "Ra" 88 end
class plutonium = object inherit atom "Plutonium" "Pu" 94 end

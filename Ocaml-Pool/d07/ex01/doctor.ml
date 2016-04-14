class doctor (pName:string) (pAge:int) (pPeople:People.people) =
object (self)
    initializer print_endline "A great doctor arrived..." ; self#regenerate
    val name:string = pName
    val mutable age:int = pAge
    val sidekick = pPeople
    val mutable hp:int = 100
    method to_string = "name=" ^ name ^ " age=" ^ string_of_int age ^ " hp=" ^ string_of_int hp ^ " sidekick=(" ^ sidekick#to_string ^ ")"
    method talk = print_endline ("Hi! I’m the Doctor!")
    method travel_in_time (start:int) (arrival:int) = print_endline "
_______(_@_)_______
| POLICE      BOX |
|_________________|
 | _____ | _____ |
 | |###| | |###| |
 | |###| | |###| | 
 | _____ | _____ |
 | || || | || || |
 | ||_|| | ||_|| |
 | _____ |$_____ |
 | || || | || || |
 | ||_|| | ||_|| |
 | _____ | _____ |
 | || || | || || | 
 | ||_|| | ||_|| | 
 |       |       | 
 *****************" ;
 		if (start > arrival) then print_endline ("Wow, the doctor travel " ^ string_of_int (start - arrival) ^ " years in the past ! But he came back in present instantanly...")
		else if (start < arrival) then print_endline ("Wow, the doctor travel " ^ string_of_int (arrival - start) ^ " years in the future ! But he came back in present instantanly...")
		else print_endline "Damn, the doctor is trying to travel to now... Useless..."
	method use_sonic_screwdriver = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"
	method private regenerate = hp <- 100
end

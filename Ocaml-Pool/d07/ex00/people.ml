class people (pName:string) =
object
    initializer print_endline "An awesome people is born !"
    val name:string = pName
    val hp:int = 100
    method to_string = "name=" ^ name ^ " hp=" ^ string_of_int hp
    method talk = print_endline ("I’m " ^ name ^ "! Do you know the Doctor?")
    method die = print_endline "Aaaarghh!"
end

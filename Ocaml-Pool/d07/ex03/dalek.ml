let getRandString3 () =
    let rand1 = Random.int 52 in
    let rand2 = Random.int 52 in
    let rand3 = Random.int 52 in
    let str1 = if (rand1 < 26) then String.make 1 (char_of_int(rand1+65)) else String.make 1 (char_of_int(rand1+71)) in
    let str2 = if (rand2 < 26) then String.make 1 (char_of_int(rand2+65)) else String.make 1 (char_of_int(rand2+71)) in
    let str3 = if (rand3 < 26) then String.make 1 (char_of_int(rand3+65)) else String.make 1 (char_of_int(rand3+71)) in
    (str1 ^ str2 ^ str3)

let bool_to_string (b:bool) = if (b = true) then "true" else "false"

class dalek =
object (self)
    val name:string = "Dalek" ^ getRandString3 ()
    val hp:int = 100
    val mutable shield:bool = true
    method private invert_shield = if (shield = true) then shield = false else shield = true
    method to_string = "name=" ^ name ^ " hp=" ^ (string_of_int hp) ^ " shield=" ^ (bool_to_string shield)
    method talk = match (Random.int 4) with
        | 0 -> print_endline "Explain! Explain!"
        | 1 -> print_endline "Exterminate! Exterminate!"
        | 2 -> print_endline "I obey!"
        | _ -> print_endline "You are the Doctor! You are the enemy of the Daleks!"
    method exterminate (toKill:People.people) = toKill#die ; self#invert_shield
    method die = print_endline "Emergency Temporal Shift!"
end

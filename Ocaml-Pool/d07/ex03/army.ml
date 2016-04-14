class ['a] army =
object
    val lst = ([]:'a list)
    method add newElem = {< lst = lst @ [newElem] >}
    method delete = match lst with | [] -> {<>} | head::tail -> {< lst = tail >}
    method size = List.length lst
end

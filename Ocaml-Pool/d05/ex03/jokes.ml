let file2array fd :string array =
  let lst = ref [] in
  begin
    try
        while true do lst := (input_line fd)::(!lst); done;
    with
    | _   -> ();
  end;
  Array.of_list !lst

let main av ac =
    if (ac != 2) then
        raise (Invalid_argument "");
    let fd = open_in av.(1) in
    let arr = file2array fd in
    close_in fd;
    if (Array.length arr = 0) then raise (Sys_error "No joke");
    Random.self_init ();
    print_endline arr.(Random.int (Array.length arr))

let () =
    try (main Sys.argv (Array.length Sys.argv)) with
    | Sys_error err -> print_endline err
    | Invalid_argument err -> print_endline ("usage: " ^ Sys.argv.(0) ^ " <jokefile>")
    | _ -> print_endline "error"

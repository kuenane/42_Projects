let my_sleep () = Unix.sleep 1

let ft_sleep av =
	for i = (int_of_string(av.(1))-1) downto 0 do
		my_sleep ()
	done

let () =
	if (Array.length Sys.argv == 2) then
		try (ft_sleep Sys.argv) with
			| _ -> ()

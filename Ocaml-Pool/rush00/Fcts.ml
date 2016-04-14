(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Fcts.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: rbrathie <rbrathie@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/04/09 18:51:23 by rbrathie          #+#    #+#             *)
(*   Updated: 2016/04/10 15:24:35 by wide-aze         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type coord = { lin:int; col:int}

let record2tuple (record:coord) = (record.lin,record.col)

let print_coord (coord:coord) =
    print_char '(';
    print_int coord.lin;
    print_string ", ";
    print_int coord.col;
    print_endline ")"

let newCoord (lignes:int) (colonnes:int) = { lin = lignes ; col = colonnes }

let rec getPlayerOne (): string =
    print_string "First player name: ";
    let name = read_line () in
    if (name = "") then
    begin
        print_endline "You must put a valid name\n";
        getPlayerOne ()
    end
    else
        name

let rec getPlayerTwo p1 =
    print_string "Second player name: ";
    let name = read_line () in
    if (name = "") then
    begin
        print_endline "You must put a valid name\n";
        getPlayerTwo p1
    end
    else if (p1 = name) then
    begin
        print_endline "This name is already used by the other player\n";
        getPlayerTwo p1
    end
    else
        name

let get_coord (board) (player:string) (playerNb:char) =
    let isdigit (c:char) = if (int_of_char c < 49 || int_of_char c > 57) then false else true in
    let rec loop board =
        let str = read_line () in

        (* la len doit etre a trois avec en 0 un chiffre, en 1 un espace et en 2 un chiffre *)
        if (String.length str != 3 || isdigit(String.get str 0) = false || (String.get str 1) <> ' ' || isdigit(String.get str 2) = false) then
        begin
            print_endline "Incorrect format.";
            loop board
        end
        else
            (* build the coord received *)
            let coord = newCoord (int_of_char(String.get str 0) - 49) (int_of_char(String.get str 2) - 49) in

            (* check if the corresponding point in board is free *)
            if ((Board.isPosFree board (coord.lin,coord.col)) = true) then
            begin
                coord
            end
            else
            begin
                print_endline "Position not free";
                loop board
            end
    in

    let playerColor = if (playerNb = 'X') then "\027[1;34m" else "\027[31m" in

    print_endline (playerColor ^ player ^ "'s turn to play\027[0m");

    loop board

let ask_if_replay () =
    print_string "\nReplay (yes/no) ?? ";
    let str = read_line () in
    if (str = "yes" || str = "y" || str = "YES" || str = "Y") then
        true
    else
        false
(* ************************************************************************** *)

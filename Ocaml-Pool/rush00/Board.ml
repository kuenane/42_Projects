(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Board.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/04/09 12:38:22 by wide-aze          #+#    #+#             *)
(*   Updated: 2016/04/10 15:30:03 by wide-aze         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

(*    9 * ( 1state + 9boxes ) = string of 90    *)
type t = string

(* return an empty and initialised board *)
let empty () = String.make 90 '-'

(* get the grid number from a couple of coord *)
let gridNbFromCoord (line,col) = match line with
	| x when x < 3 -> if (col < 3) then 0 else if (col < 6) then 1 else 2
	| x when x < 6 -> if (col < 3) then 3 else if (col < 6) then 4 else 5
	| _ -> if (col < 3) then 6 else if (col < 6) then 7 else 8

(* get the real string position from a couple of coord *)
let strPosFromCoord (line,col) = (10 * gridNbFromCoord (line,col)) + 1 + (col mod 3) + ((line mod 3) * 3)

(* insert the coord in the board and return an updated board !! NO PROTECTION !! *)
let insertCoord (board:t) (lin,col) (player:char) = Bytes.set board (strPosFromCoord (lin,col)) player ; board

(* dump the board *)
let dump (board:t) =
	let print_char_red (c:char) = print_string "\027[31m" ; print_char c ; print_string "\027[0m" in
	let print_char_blue (c:char) = print_string "\027[1;34m" ; print_char c ; print_string "\027[0m" in
	let print_char_grey (c:char) = print_string "\027[1;30m" ; print_char c ; print_string "\027[0m" in
	let print_one_cell board n =
		let cur_char = String.get board n in
		match cur_char with
			| 'X' -> print_char_blue cur_char ; print_char ' '
			| 'O' -> print_char_red cur_char ; print_char ' '
			| _ -> print_char cur_char ; print_char ' '
	in
	let print_3_cells board n = print_one_cell board (n); print_one_cell board (n+1) ;print_one_cell board (n+2) in
	let print_one_line board n =
		print_3_cells board n ;
		print_char_grey '|' ; print_char ' ';
		print_3_cells board (n+10) ;
		print_char_grey '|' ; print_char ' ';
		print_3_cells board (n+20) ;
		print_char '\n'
	in
	let print_3_lines board n = print_one_line board (n); print_one_line board (n+3) ;print_one_line board (n+6) in
	let rec print_all board =
 		print_3_lines board 1;
		print_endline "\027[1;30m---------------------\027[0m";
		print_3_lines board 31;
		print_endline "\027[1;30m---------------------\027[0m";
		print_3_lines board 61;
	in
	print_char '\n' ; print_all board ; print_char '\n'

(* get the content from the grid nth *)
let getGridContent (board:t) (n:int) = String.sub board ((n * 10) + 1) 9

(* get the state from the grid nth *)
let getGridState (board:t) (n:int) = String.get board (n * 10)

(* get the full grid nth (1 state + 9 content) *)
let getFullGrid (board:t) (n:int) = String.sub board (n * 10) 10

(* check if the grid n is finished *)
let isGridFinished (board:t) (n:int) = if (getGridState board n <> '-') then true else false

(* check if there is a winner *)
let checkWinner (str:string) (player:char) (multi:int) =
	if (String.get str (0*multi) == player && String.get str (1*multi) == player && String.get str (2*multi) == player)
	|| (String.get str (3*multi) == player && String.get str (4*multi) == player && String.get str (5*multi) == player)
	|| (String.get str (6*multi) == player && String.get str (7*multi) == player && String.get str (8*multi) == player)
	|| (String.get str (0*multi) == player && String.get str (3*multi) == player && String.get str (6*multi) == player)
	|| (String.get str (1*multi) == player && String.get str (4*multi) == player && String.get str (7*multi) == player)
	|| (String.get str (2*multi) == player && String.get str (5*multi) == player && String.get str (8*multi) == player)
	|| (String.get str (0*multi) == player && String.get str (4*multi) == player && String.get str (8*multi) == player)
	|| (String.get str (2*multi) == player && String.get str (4*multi) == player && String.get str (6*multi) == player)
	then
		true
	else
		false

(* check if the board is full *)
let isBoardFull (board:t) = 
	let rec loop (board:t) (n:int) =
	if (n > 8) then
		true
	else if (getGridState board n <> '-') then
		loop board (n+1)
	else 
		false
	in
	loop board 0

(* check if the entiere board is finished *)
let isBoardFinished (board:t) (player1:string) (player2:string) (curplayer:char) =
	if (checkWinner board 'X' 10) then
	begin
		print_string "\027[1;34m" ; print_string player1 ; print_endline " wins the game!\027[0m" ; true
	end
	else if (checkWinner board 'O' 10) then
	begin
		print_string "\027[31m" ; print_string player2 ; print_endline " wins the game!\027[0m" ; true
	end
	else if (isBoardFull board = true) then
	begin
		if (curplayer = 'X') then
		begin
			print_string "\027[1;34m" ; print_string player1 ; print_endline " wins the game!\027[0m" ; true
		end
		else
		begin
			print_string "\027[31m" ; print_string player2 ; print_endline " wins the game!\027[0m" ; true
		end
	end
	else
		false

(* set the finished grid n *)
let setAsFinished board n player = 
	let posBegin = (n * 10) in
	print_char player ; print_string " wins grid " ; print_int (n+1) ; print_endline "!";
	if (player = 'X') then
	begin
		Bytes.set board (posBegin) 'X' ; Bytes.set board (posBegin+1) '\\';
		Bytes.set board (posBegin+2) ' ' ; Bytes.set board (posBegin+3) '/';
		Bytes.set board (posBegin+4) ' ' ; Bytes.set board (posBegin+5) 'x';
		Bytes.set board (posBegin+6) ' ' ; Bytes.set board (posBegin+7) '/';
		Bytes.set board (posBegin+8) ' ' ; Bytes.set board (posBegin+9) '\\';
		board
	end
	else
	begin
		Bytes.set board (posBegin) 'O' ; Bytes.set board (posBegin+1) '/';
		Bytes.set board (posBegin+2) '-' ; Bytes.set board (posBegin+3) '\\';
		Bytes.set board (posBegin+4) '|' ; Bytes.set board (posBegin+5) ' ';
		Bytes.set board (posBegin+6) '|' ; Bytes.set board (posBegin+7) '\\';
		Bytes.set board (posBegin+8) '-' ; Bytes.set board (posBegin+9) '/';
		board
	end

(* update the status for the grid n and return an updated board *)
let updateGridStatus (board:t) (n:int) (player:char) =
begin

	let grid = getGridContent board n in
	let state = getGridState board n in

	(* if the board is already finished, don't touch it *)
	if (state != '-') then
		board

	(* check if X win *)
	else if (checkWinner grid 'X' 1) then
		setAsFinished board n 'X'

	(* check if O win *)
	else if (checkWinner grid 'O' 1) then
		setAsFinished board n 'O'

	(* check if the grid is full *)
	else if (String.contains grid '-' = false) then
		setAsFinished board n player

	(* else we return same board *)
	else
		board
end

(* update the status for the entire board and return an updated board *)
let updateBoardStatus (board:t) (player:char) = 
	let rec loop (board:t) (n:int) =
		if (n < 9) then
			loop (updateGridStatus board n player) (n+1)
		else
			board
	in
	loop board 0

(* check if a given coord is free or not *)
let isPosFree (board:t) (l,c) =
	if (isGridFinished board (gridNbFromCoord (l,c)) = true) then
		false
	else if (String.get board (strPosFromCoord (l,c)) = '-') then
		true
	else
		false

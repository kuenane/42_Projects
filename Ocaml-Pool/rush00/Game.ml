(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Game.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: rbrathie <rbrathie@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/04/09 18:38:22 by rbrathie          #+#    #+#             *)
(*   Updated: 2016/04/10 15:47:59 by wide-aze         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let startGame () =

    let player1 = Fcts.getPlayerOne () in

    let player2 = Fcts.getPlayerTwo player1 in

    print_endline ("\nWelcome " ^ player1 ^ " and " ^ player2);

    let rec loop (board:Board.t) (p1:string) (p2:string) (curplayer:char) =

    	Board.dump board;

    	let coord = if (curplayer = 'X') then Fcts.get_coord board p1 curplayer else Fcts.get_coord board p2 curplayer in

    	let newBoard = Board.insertCoord board (Fcts.record2tuple coord) curplayer in

    	let updatedBoard = Board.updateBoardStatus newBoard curplayer in

    	let next_player curplayer = if (curplayer = 'X') then 'O' else 'X' in

    	if (Board.isBoardFinished updatedBoard p1 p2 curplayer = false) then
    		loop updatedBoard p1 p2 (next_player curplayer)
    	else
    	begin
    		Board.dump updatedBoard;
    		if (Fcts.ask_if_replay () == true) then
				loop (Board.empty ()) player1 player2 'O'
    	end
    in

	loop (Board.empty ()) player1 player2 'O'

(*
	function principal :
	    4. insertion
	    5. update board
	    6. if isBoardFinished = false -> rappel de la fonction principal
*)


(* ************************************************************************** *)

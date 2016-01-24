member(X,[X|_]).
member(X,[_|T]) :- member(X,T).

/*len([],0).
len([_|T],N) :- len(T,X), N is X+1.*/

accLen([_|T],A,L) :- Anew is A+1, accLen(T,Anew,L).
accLen([],L,L).
len(List,N) :- accLen(List,0,N).

append([],L,L).
append([H|T],L2,[H|L3]) :- append(T,L2,L3).

prefix(P,L) :- append(P,_,L).

suffix(S,L) :- append(_,S,L).

sublist(SubL,L) :- suffix(S,L), prefix(SubL,S).

find(X,Maisons) :-
    Maisons = [M1,_,M3,_,_],
    member(house(rouge,anglais,_,_,_),Maisons),
    member(house(_,suédois,chiens,_,_),Maisons),
    member(house(_,danois,_,thé,_),Maisons),
    sublist([house(verte,_,_,_,_),house(blanche,_,_,_,_)],Maisons),
    member(house(verte,_,_,café,_),Maisons),
    member(house(_,_,oiseaux,_,'Pall Mall'),Maisons),
    member(house(jaune,_,_,_,'Dunhill'),Maisons),
    M3 = house(_,_,_,lait,_),
    M1 = house(_,norvégien,_,_,_),
    (sublist([house(_,_,chats,_,_),house(_,_,_,_,'Blend')],Maisons) ;
     sublist([house(_,_,_,_,'Blend'),house(_,_,chats,_,_)],Maisons)),
    (sublist([house(_,_,cheval,_,_),house(_,_,_,_,'Dunhill')],Maisons) ;
     sublist([house(_,_,_,_,'Dunhill'),house(_,_,cheval,_,_)],Maisons)),
    member(house(_,_,_,bière,'Blue Master'),Maisons),
    member(house(_,allemand,_,_,'Prince'),Maisons),
    (sublist([house(bleue,_,_,_,_),house(_,norvégien,_,_,_)],Maisons) ;
     sublist([house(_,norvégien,_,_,_),house(bleue,_,_,_,_)],Maisons)),
    (sublist([house(_,_,_,eau,_),house(_,_,_,_,'Blend')],Maisons) ;
     sublist([house(_,_,_,_,'Blend'),house(_,_,_,eau,_)],Maisons)),
    member(house(_,X,poisson,_,_),Maisons).

final_set(Maisons) :-
	find(_,Maisons).

poisson(X) :-
	find(X,_).

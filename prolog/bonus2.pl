/*
Les deux portes menaient au même endroit et au lieu de découvrir la princesse il vit le roi.
Voici deux nouvelles portes avec chacune une inscription.
Cette fois, l une d entre elles dit la vérité et l autre ment.

PANCARTE1 -> Il y a une princesse dans cette cellule et un tigre dans l autre.

PANCARTE2 -> Il y a une princesse dans une cellule et un tigre dans l autre.
*/

contenu(Porte) :- (Porte = 'Princesse' ; Porte = 'Tigre').

pancarte1(X,Y) :- X = 'Princesse' , Y = 'Tigre'.

pancarte2(X,Y) :- ((X = 'Princesse', Y = 'Tigre') ; (Y = 'Princesse', X = 'Tigre')).

xor(X,Y) :- (X,not(Y));(not(X),Y).
    
salle2(X,Y) :- contenu(X), contenu(Y), xor(pancarte1(X,Y),pancarte2(X,Y)).

salle2() :- salle2(X,Y),write('La premiere porte contient: '),write(X),
    write('\nLa deuxieme porte contient: '),write(Y).

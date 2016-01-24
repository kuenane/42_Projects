/*
Un prisonnier est devant deux portes, chacune ayant une pancarte.
Le roi dit au prisonnier : « Votre sort sera décidé par la porte que vous allez passer.
Si vous vous trompez, je ne donne pas cher de votre peau.
Si vous choisissez bien, je vous donne la main de la princesse.
Les indications sur les portes vous aideront à trouver le bon chemin.
Les pancartes disent soit la vérité, soit mentent toutes les deux.

PANCARTE1 -> Il y a un tigre derrière cette porte, ou la princesse derrière l autre.

PANCARTE2 -> La princesse est derrière l autre porte.
*/

contenu(Porte) :- (Porte = 'Princesse' ; Porte = 'Tigre').

pancarte1(X,Y) :- X = 'Tigre' ; Y = 'Princesse'.

pancarte2(X) :- X = 'Princesse'.

salle1(X,Y) :- contenu(X), contenu(Y), pancarte1(X,Y) , pancarte2(X).

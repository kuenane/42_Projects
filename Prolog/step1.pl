femme(anne).
femme(betty).
femme(lisa).
femme(sylvie).
femme(eve).
femme(julie).
femme(valérie).

homme(marc).
homme(luc).
homme(jean).
homme(jules).
homme(léon).
homme(loic).
homme(gérard).
homme(jacques).
homme(hervé).
homme(paul).

mari_de(marc,anne).
mari_de(luc,betty).
mari_de(jules,lisa).
mari_de(léon,sylvie).
mari_de(loic,eve).
mari_de(paul,julie).

femme_de(Femme,Mari) :- mari_de(Mari,Femme).

enfant_de(jean,marc).
enfant_de(jules,marc).
enfant_de(léon,marc).
enfant_de(lisa,luc).
enfant_de(loic,luc).
enfant_de(gérard,luc).
enfant_de(jacques,jules).
enfant_de(hervé,léon).
enfant_de(julie,léon).
enfant_de(paul,loic).
enfant_de(valérie,loic).

enfant_de(Enfant,Mere) :- mari_de(Pere,Mere), enfant_de(Enfant,Pere).

beaupere_de(BeauPere,BelEnfant) :- (mari_de(BelEnfant,Enfant);femme_de(BelEnfant,Enfant)), enfant_de(Enfant,BeauPere), homme(BeauPere).

bellemere_de(BelleMere,BelEnfant) :- (mari_de(BelEnfant,Enfant);femme_de(BelEnfant,Enfant)), enfant_de(Enfant,BelleMere), femme(BelleMere).

ancetre_de(Asc,Dsc) :- (enfant_de(Dsc,Asc) ; enfant_de(X, Asc),ancetre_de(X,Dsc)).

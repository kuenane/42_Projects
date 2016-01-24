animal(animalia).
 animal(chondrichthyes).
  animal(requin).
 animal(chordata).
  animal(marsupialia).
   animal(kangourou).
   animal(koala).
  animal(placentalia).
   animal(homme).
   animal(chimpanze).
   animal(elephant).
   animal(renard).

    
enfant_de(chondrichthyes, animalia).
enfant_de(requin, chondrichthyes).
enfant_de(chordata, animalia).
enfant_de(marsupialia,chordata).
enfant_de(kangourou,marsupialia).
enfant_de(koala,marsupialia).
enfant_de(placentalia,chordata).
enfant_de(homme,placentalia).
enfant_de(chimpanze,placentalia).
enfant_de(elephant,placentalia).
enfant_de(renard,placentalia).

parent_de(Parent,Enfant) :- enfant_de(Enfant,Parent).
    
ancetre_de(Asc,Dsc) :- (enfant_de(Dsc,Asc) ; enfant_de(X, Asc),ancetre_de(X,Dsc)).
    
descendant_de(Dsc,Asc) :- (enfant_de(Dsc,Asc) ; enfant_de(X, Asc),ancetre_de(X,Dsc)).
    
frere_de(F1,F2) :- enfant_de(F1,X), enfant_de(F2,X), F1 \= F2.

ancetre_commun_de(E1,E2,Ancetre) :- ancetre_de(Ancetre,E1), ancetre_de(Ancetre,E2).



############################## VARS ############################
NAME = tic-tac-toe

SOURCES = Board.ml Fcts.ml Game.ml main.ml

CAMLC = ocamlc
CAMLOPT = ocamlopt
CAMLDEP = ocamldep

# do like WITHGRAPHICS for others libraries
LIBS = 
WITHGRAPHICS = graphics.cma -cclib -lGraphics
###############################################################

############################# RULES ###########################
all: depend $(NAME)

$(NAME): opt byt
	@ln -fs $(NAME).byt $(NAME)

opt: $(NAME).opt
byt: $(NAME).byt

OBJS = $(SOURCES:.ml=.cmo)
OPTOBJS = $(SOURCES:.ml=.cmx)
###############################################################

############################### LNK ###########################
$(NAME).byt: $(OBJS)
	@$(CAMLC) -o $(NAME).byt $(LIBS) $(OBJS)

$(NAME).opt: $(OPTOBJS)
	@$(CAMLOPT) -o $(NAME).opt $(LIBS:.cma=.cmxa) $(OPTOBJS)
###############################################################

########################### COMPIL. ###########################
.SUFFIXES:
.SUFFIXES: .ml .mli .cmo .cmi .cmx

.ml.cmo:
	@$(CAMLC) -c $<

.mli.cml:
	@$(CAMLC) -c $<

.ml.cmx:
	@$(CAMLOPT) -c $<
###############################################################

############################# CLEAN ###########################
clean:
	@rm -rf *.cm[iox] *~ .*~ *.o .depend

fclean: clean
	@rm -rf $(NAME) $(NAME).opt $(NAME).byt

depend: .depend
	@$(CAMLDEP) $(SOURCES) > .depend

re: fclean all

$(shell touch .depend)
include .depend


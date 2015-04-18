
NAME = ft_retro

SRCSFILES = \
			main.cpp\
			AObject.class.cpp\
			Background.class.cpp\
			Game.class.cpp\
			Scheduler.class.cpp\
			Shape.class.cpp\
     ./mobs/Player.class.cpp\
     ./mobs/Missile.class.cpp\
     ./mobs/Pig.class.cpp\
     ./mobs/Sheep.class.cpp\
     ./mobs/Snake.class.cpp\
     ./mobs/Centipede.class.cpp\
     ./mobs/Lombric.class.cpp\
     ./mobs/Fizzy.class.cpp\
     ./move/IMovIA.class.cpp\
     ./move/AMovPatternDefault.class.cpp\
     ./move/AMovPatternSheep.class.cpp\
     ./move/AMovPatternLombric.class.cpp\
     ./move/AMovPatternMissile.class.cpp\
    ./shoot/IShootIA.class.cpp\
    ./shoot/AShootPatternDefault.class.cpp

SRCPATH = .
OBJPATH = obj
# CC = g++
CC = clang++
INCLUDES = -I . -I ./mobs/ -I ./move/ -I ./shoot/
LIBS = -lncurses
CFLAGS = -Werror -Wall -Wextra -O2 -g
RM = rm -rf

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling all"
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

##
## EPITECH PROJECT, 2022
## gomuku
## File description:
## gomoku project
##


SRC		        =	main.cpp \
                    Sources/launcher.cpp \
                    Sources/Gui/gui.cpp \
                    Sources/Library/sfml.cpp \


OBJ		        =	$(SRC:.cpp=.o)

NAME            =   Epipov-Ray

CXXFLAGS	    +=	-W -Wall -Wextra -Werror -std=c++17 -I./Includes -I./Includes/Interfaces -I./Includes/Gui -I./Includes/Library

SFMLFLAGS	    =	-lsfml-graphics -lsfml-window -lsfml-system

CXX 	=	g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(SFMLFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CXXFLAGS += -g -g3
debug:	fclean
debug: all

.PHONY: all clean fclean re debug

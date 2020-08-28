CC			=	g++

RM			=	rm -f

NAME		=	snake

SRC			=	source/main.cpp		\
				source/controls.cpp	\
				source/move_head.cpp\
				source/move.cpp		\
				source/refresh.cpp	\
				source/display.cpp	\
				source/tools.cpp	\

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I ./include
CXXFLAGS	+=	-Wall
CXXFLAGS	+=	-lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(CXXFLAGS) $(OBJ)
			@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"

clean:
			@$(RM) $(OBJ)
			@echo -e "\e[91m[CORE] \e[38;5;206mRemoving object files...\e[39m"

fclean:		clean
			@$(RM) $(NAME)
			@echo -e "\e[91m[CORE] \e[38;5;206mRemoving binary files...\e[39m"

re:			fclean all

%.o:		%.cpp
			@$(CC) $(CXXFLAGS) -c -o $@ $<

.PHONY:		all clean fclean re
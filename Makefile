##
## EPITECH PROJECT, 2025
## B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
## File description:
## Makefile
##

NAME	=	raytracer

SRC	=	$(wildcard src/*.cpp) $(wildcard include/*.cpp)

LIBS	=	$(shell pkg-config --libs libconfig++)

CFLAGS	=	$(shell pkg-config --cflags libconfig++)

all: $(NAME)


$(NAME):
	g++ $(CFLAGS) -o $(NAME) $(SRC) -I ./include $(LIBS)
	@echo "\033[32m= = = = =  COMPILATION COMPLETED  = = = = =\033[0m"

clean:
	@$(RM) $(NAME)
	@$(RM) ./src/*.o

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *~
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all
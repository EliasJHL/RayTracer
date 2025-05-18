##
## EPITECH PROJECT, 2025
## B-OOP-400-MPL-4-1-raytracer-elias-josue.hajjar-llauquen
## File description:
## Makefile
##

NAME	=	raytracer

SFML_FLAGS	=	-L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC	=	$(shell find src include -name "*.cpp")

LIBS	=	$(shell pkg-config --libs libconfig++)

PLUGINS_SRC	=	./plugins/materials/mirror.cpp $(wildcard ./src/*.cpp) $(wildcard ./src/Raytracer/Lights/*.cpp)

CFLAGS	=	$(shell pkg-config --cflags libconfig++)

all: $(NAME)

$(NAME): plugins
	g++ -std=c++17 $(CFLAGS) -o $(NAME) $(SRC) -I ./include $(LIBS) $(SFML_FLAGS)
	@echo "\033[32m= = = = =  COMPILATION COMPLETED  = = = = =\033[0m"

.PHONY: plugins
plugins:
	g++ -shared -fPIC $(PLUGINS_SRC) -o raytracer_mirror.so -I ./include
	@mv *.so ./plugins/
	@echo "\033[32m= = = = =  PLUGINS COMPLETED  = = = = =\033[0m"

clean:
	@$(RM) $(NAME)
	@$(RM) ./src/*.o
	@$(RM) ./plugins/*.so
	@$(RM) *.ppm

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *~
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all
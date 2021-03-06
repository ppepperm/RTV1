# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 12:14:41 by ppepperm          #+#    #+#              #
#    Updated: 2020/05/26 19:42:03 by ppepperm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= RTv1
SRC :=	src/inits.c src/linal.c src/main.c src/trace.c src/input.c src/free.c\
src/qaternion.c src/light.c src/chose.c src/transform.c src/intersections.c src/controls.c src/pthread.c\
src/returns.c src/objects.c src/lights.c src/validation.c src/shadows.c src/events.c src/norms.c src/effect.c

OBJ := $(SRC:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror -I includes
LIB_FLAG :=  -L libft/ -lft `./SDL2-2.0.12/sdl2-config --libs --cflags` -O0
LINUX_FLAG := -L libft/ -lft `./SDL2-2.0.12/sdl2-config --libs --cflags` -O0  -lm
PATH_SDL := $(PWD)/SDL2-2.0.12
SDL = $(PWD)/SDL2-2.0.12/sdl2-config
INCLUDES := includes SDL2

all: $(NAME)

$(SDL):
	cd $(PATH_SDL); ./configure --prefix=$(PATH_SDL); make;
	make -sC $(PATH_SDL) install

%.o : src/%.c $(INCLUDES)
		gcc -c $(CFLAGS) -I $(INCLUDES) $SSRC -o
		@echo $(SSRC:src/%.c = %)

$(NAME): $(OBJ) $(SDL)
		@make -C libft
		@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LINUX_FLAG)
		@echo "DONE"

MAC : $(OBJ) $(SDL)
		@make -C libft
		@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FLAG)
		@echo "DONE"

clean:
		@rm -f $(OBJ)
		@make -C libft clean

fclean: clean
		@rm -f $(NAME)
		@make -C libft fclean

re: fclean $(NAME)

.PHONY: all clean
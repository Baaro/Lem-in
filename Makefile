# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 13:02:59 by vsokolog          #+#    #+#              #
#    Updated: 2018/07/10 13:03:00 by vsokolog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC := gcc
FLAGS := -Wall -Wextra -Werror -g
INCLUDES := includes/
source_dirs :=	srcs	\

OBJ_DIR := objs
INCLUDES := includes/
MAKE := make
RM := rm -rf
LIBFT := libft/libft.a

search_wildcards := $(addsuffix /*.c, $(source_dirs))

OBJ = $(notdir $(patsubst %.c, %.o, $(wildcard $(search_wildcards))))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) -o $@ $(OBJ) $(LIBFT)

VPATH := $(source_dirs)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@
	
clean:$
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY: clean fclean re all
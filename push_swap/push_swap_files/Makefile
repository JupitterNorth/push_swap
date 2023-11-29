# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:51:25 by gneto-co          #+#    #+#              #
#    Updated: 2023/11/29 11:20:11 by gneto-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

FUNCTIONS_SOURCES = $(addprefix functions/, \
stack_creation.c \
organize.c \
)

OPERATIONS_SOURCES = $(addprefix operations/, \
swap.c \
push.c \
rotate.c \
reverse_rotate.c \
)

SOURCES = $(OPERATIONS_SOURCES) $(FUNCTIONS_SOURCES)
	
OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
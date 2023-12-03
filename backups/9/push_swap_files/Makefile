# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneto-co <gneto-co@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:51:25 by gneto-co          #+#    #+#              #
#    Updated: 2023/12/03 13:37:59 by gneto-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

PROJECT_SOURCES = \
push_swap.c \

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

ALGORITHM_SOURCES = $(addprefix algorithm/, \
order_verification.c \
al_utils.c \
sort.c \
algorithm1.c \
algorithm2.c \
)

SOURCES = $(PROJECT_SOURCES) $(OPERATIONS_SOURCES) $(FUNCTIONS_SOURCES) $(ALGORITHM_SOURCES)
	
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
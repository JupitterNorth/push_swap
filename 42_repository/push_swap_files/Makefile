# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:51:25 by gneto-co          #+#    #+#              #
#    Updated: 2024/02/22 16:07:09 by gneto-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

PROJECT_SOURCES = \
push_swap.c \

FUNCTIONS_SOURCES = $(addprefix functions/, \
stack_creation.c \
organize.c \
order_verification.c \
al_utils1.c \
al_utils2.c \
)

OPERATIONS_SOURCES = $(addprefix operations/, \
swap.c \
push.c \
rotate.c \
reverse_rotate.c \
)

ALGORITHM_SOURCES = $(addprefix algorithm/, \
sort.c \
algorithm1.c \
algorithm2.c \
algorithm4.c \
algorithm5.c \
algorithm6.c \
)

SOURCES = $(PROJECT_SOURCES) $(OPERATIONS_SOURCES) $(FUNCTIONS_SOURCES) $(ALGORITHM_SOURCES)
	
OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) 
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
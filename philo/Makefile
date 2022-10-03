# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bberkass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:05:34 by bberkass          #+#    #+#              #
#    Updated: 2022/10/03 19:05:42 by bberkass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

SRCS = philo.c src/atoi.c src/utils.c src/init.c src/routine.c src/time.c src/log.c src/check.c src/destroy.c

all : $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lpthread 

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all



NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = philo.c src/atoi.c src/utils.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

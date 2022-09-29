

NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = philo.c src/atoi.c src/utils.c src/time.c src/log.c src/routine.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -pthread

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

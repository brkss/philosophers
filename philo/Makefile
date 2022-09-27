


NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

SRCS = philo.c src/atoi.c src/utils.c src/init.c src/routine.c src/time.c

all : $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lpthread

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all


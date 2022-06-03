
NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread 

SRC = philo.c src/atoi.c src/forks.c src/threads.c src/utils.c src/init.c


OBJ = 

all : $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean 

re: clean all 




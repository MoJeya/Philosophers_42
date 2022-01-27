NAME = philo

FILES = main.c ./utils/ft_atoi.c ./utils/tools.c ./utils/routine_tools.c ./utils/confirm.c ./utils/free_thread.c ./utils/ft_jointhreads.c\

CFLAGS = -Wall -Wextra -Werror 

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FILES) $(CFLAGS) -g -pthread -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

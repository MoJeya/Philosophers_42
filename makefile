NAME = philo

FILES = main.c ./utils/ft_atoi.c ./utils/time_stamp.c ./utils/routine_tools.c \

CFLAGS = -Wall -Wextra -Werror 

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FILES) $(CFLAGS) -g -pthread -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
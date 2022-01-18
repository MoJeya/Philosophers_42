NAME = philo

FILES = main.c ft_time_in_ms.c \

CFLAGS = -Wall -Wextra -Werror 

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FILES) $(CFLAGS) -g -pthread -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
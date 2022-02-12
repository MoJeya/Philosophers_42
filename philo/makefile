# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:14:12 by mjeyavat          #+#    #+#              #
#    Updated: 2022/02/12 13:29:46 by mjeyavat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FILES = philosophers.c ../utils/ft_atoi.c ../utils/tools.c ../utils/routine_tools.c ../utils/confirm.c ../utils/free_thread.c ../utils/ft_jointhreads.c\

CFLAGS = -Wall -Wextra -Werror 

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FILES) $(CFLAGS) -g -pthread -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

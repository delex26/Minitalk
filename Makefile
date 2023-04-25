# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-mes <hben-mes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:32:46 by hben-mes          #+#    #+#              #
#    Updated: 2023/01/16 19:32:56 by hben-mes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

BONUS = server_bonus client_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror

RM = rm -f

FILES = server.c client.c
UFILE = utils.c
BFILES = server_bonus.c client_bonus.c
BFILE = utils_bonus.c


OBJS = $(FILES:.c=.o)
UOBJ = $(UFILE:.c=.o)
BOBJS = $(BFILES:.c=.o)
BOBJ = $(BFILE:.c=.o)


all : $(NAME)


$(NAME) : $(OBJS) $(UOBJ)
	@$(CC) $(CFLAGS) $(UOBJ) server.o -o server
	@$(CC) $(CFLAGS) $(UOBJ) client.o -o client

bonus : $(BONUS) 
	
$(BONUS) :	$(BOBJS) $(BOBJ)
	@$(CC) $(CFLAGS) $(BOBJ) server_bonus.o -o server_bonus
	@$(CC) $(CFLAGS) $(BOBJ) client_bonus.o -o client_bonus

clean :
	$(RM) *.o

fclean : clean
	$(RM) client server client_bonus server_bonus

re : fclean all
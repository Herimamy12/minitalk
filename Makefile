NAMES = server

NAMEC = client

NAME_BS = server_bonus

NAME_BC = client_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAMES) $(NAMEC)

bonus : $(NAME_BS) $(NAME_BC)

$(NAMES) :
		make -C ./Mandatory/
		$(CC) -o $@ \
		./Mandatory/libserver.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a \
		./LIST/list.a \

$(NAMEC) :
		make -C ./Mandatory/
		$(CC) -o $@ \
		./Mandatory/libclient.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a \
		./LIST/list.a \

$(NAME_BS) :
		make -C ./Bonus/
		$(CC) -o $@ \
		./Bonus/libserver_bonus.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a \
		./LIST/list.a \

$(NAME_BC) :
		make -C ./Bonus/
		$(CC) -o $@ \
		./Bonus/libclient_bonus.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a \
		./LIST/list.a \

clean :
		make clean -C ./Mandatory/
		make clean -C ./Bonus/

fclean : clean
		make fclean -C ./Mandatory/
		make fclean -C ./Bonus/
		rm -f $(NAMES) $(NAMEC) $(NAME_BS) $(NAME_BC)

re : fclean all

.PHONY : all bonus clean fclean re
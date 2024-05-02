NAMES = server

NAMEC = client

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAMES) $(NAMEC)

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

clean :
		make clean -C ./Mandatory/

fclean : clean
		make fclean -C ./Mandatory/
		rm -f $(NAMES) $(NAMEC)

re : fclean all

.PHONY : all clean fclean re
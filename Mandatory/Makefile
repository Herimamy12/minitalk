NAMES = libserver.a

NAMEC = libclient.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = server.c

SRCC = client.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

OBJC = $(SRCC:.c=.o)

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAMES) $(NAMEC)

$(NAMES) : $(OBJS)
		make -C ../LIBFT/
		make -C ../LIST/
		make -C ../PRINTF/
		ar rsc $@ $^

$(NAMEC) : $(OBJC)
		make -C ../LIBFT/
		make -C ../LIST/
		make -C ../PRINTF/
		ar rsc $@ $^

clean :
		make clean -C ../LIBFT/
		make clean -C ../LIST/
		make clean -C ../PRINTF/
		rm -f $(OBJS) $(OBJC)

fclean : clean
		make fclean -C ../LIBFT/
		make fclean -C ../LIST/
		make fclean -C ../PRINTF/
		rm -f $(NAMES) $(NAMEC)

re : fclean all

.PHONY : all clean fclean re
NAME = ft_printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c libft.a

OBJS = $(SRC:.c=.o)

all : $(NAME)
	ar rcs $(SRC) -o $(NAME);

$(NAME) : $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(SRC) -o $(OBJS)

clean :
	rm $(OBJS)

fclean : claen
	rm $(NAME)

.PHONY : all clean fclean
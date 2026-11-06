NAME = ft_printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_dec.c ft_hex.c ft_string.c

OBJS = $(SRC:.c=.o)

all: $(NAME)
 
$(NAME) : $(OBJS) 
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY : all clean fclean
NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

SRCS = ft_printf_hex.c ft_printf_nbr.c ft_printf_str.c ft_printf_pointer.c \
       ft_printf_unnbr.c ft_printf.c

OBJ = $(SRCS:%.c=%.o)

RM = rm -f

.c.o :
        $(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJ)
        $(AR) $(NAME) $(OBJ)

all : $(NAME)

clean :
        $(RM) $(OBJ)

fclean : clean
        $(RM) $(NAME)

re : fclean all

.PONY : all clean fclean re

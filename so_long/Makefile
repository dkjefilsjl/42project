NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

SRCS = so_long.c get_next_line.c get_next_line_utils.c so_long_utils2.c so_long_utils.c ft_split.c

OBJ = $(SRCS:.c=.o)

RM = rm -f

$(NAME) : $(OBJ)
	@make -C mlx
	$(AR) $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L ./mlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

clean :
	$(RM) $(OBJ)
	@make -C mlx clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY :	all clean fclean re

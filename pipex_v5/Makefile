NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

SRCS = go_pipex.c main.c ft_split.c libft.c pipex.c utils.c

OBJ = $(SRCS:.c=.o)

RM = rm -f

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY :	all clean fclean re

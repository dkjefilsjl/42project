NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=thread

SRCS = philo.c dinary.c simul.c util.c util2.c

OBJ = $(SRCS:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY :	all clean fclean re

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

BONUS = checker

SRCS = push_swap_parse.c push_swap_libft.c push_swap_sort.c \
	ft_split.c push_swap_libft_two.c push_swap_sort_two.c \
	push_swap.c push_swap_node.c push_swap_utils.c

BONUS_SRCS = checker.c get_next_line.c get_next_line_utils.c \
	push_swap_libft_two.c push_swap_libft.c push_swap_parse.c \
	ft_split.c push_swap_node.c push_swap_utils.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

RM = rm -f

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(BONUS) : $(BONUS_OBJ)
	$(AR) $(BONUS) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ)

clean :
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY :	all clean fclean re

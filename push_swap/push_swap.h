#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

# define INT_MAX 2147483647

typedef struct s_node
{
	int value;
	int id;
	struct s_node *next;
	struct s_node *prev;
}   t_node;

typedef struct s_data
{
	t_node *head;
	t_node *tail;
	int size;
}   t_data;

char	**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
t_node	*newNode(int data);
void	add_node(t_data *list, int data);
void	ft_exit(char *s);
void	init_ab(t_data *td);
int		ft_isdigit(int c);
void	parse_data(t_data *list, int i, char *argv[]);
void	push_data_a(t_data *a, int argc, char *argv[]);
void	ft_check_digit(char *str);
void	ft_swap(t_data *list);
void	ft_rotate (t_data *list);
void	ft_rrotate(t_data *list);
void	ft_push(t_data *to, t_data *from);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *s);

#endif
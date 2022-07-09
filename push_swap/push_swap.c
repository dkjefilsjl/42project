#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
	struct s_node *prev;
}   t_node;

typedef struct s_data
{
	t_node *head;
	t_node *tail;
	unsigned int len;
	int max;
	int min;
	int *sort;
	int sort_num;
}   t_data;

t_node *newNode(int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = data;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

t_node *addNode(t_node *list, int data)
{
	t_node *new;

	if(list == NULL)
		new = newNode(data);
	else
	{
		new = newNode(data);
		list->next = new;
		new->next = NULL;
		new->prev = list;
	}
	return (new);
}

int find_Node(t_node *list, int data)
{

}

void ft_exit()
{
	exit(1);
}

void init_a(t_data *a)
{
	a->head = NULL;
	a->tail = NULL;
	a->len = 0;
	a->max = 0;
	a->min = 0;
	a->sort = 0;
	a->sort_num = 0;
}

void	parse_data(t_node *list, int i, char *argv[])
{
	char	**data;
	int		i;
	int		d;

	i = -1;
	data = ft_split(argv[i], ' ');
	if (!data)
		ft_exit();
	while (data[++i])	
	{
		d = ft_atoi(data[i]);
		if (!d)
			ft_exit();
		addNode(&list, d);
	}
	return ;
}

void push_data_a(t_data *a, int argc, char *argv[])
{
	int	i;
	t_node	list;

	i = -1;

	while (++i < argc)
	{
		parse_data(&list, i, argv);
	}

}

int main(int argc, char *argv[])
{
	int i;
	int j;
	t_data a;
	t_data b;
	
	if (argc == 1)
		ft_exit();
	init_a(&a);
	push_data_a(&a, argc, argv);
}
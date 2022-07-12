#include "push_swap.h"

void	ft_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	init_ab(t_data *td)
{
	td->head = NULL;
	td->tail = NULL;
	td->size = 0;
}

void	parse_data(t_data *list, int i, char *argv[])
{
	char	**data;
	long long	d;
	int		j;

	j = -1;
	data = ft_split(argv[i], ' ');
	if (!data)
		ft_exit("Error");
	while (data[++j])
	{
		ft_check_digit(data[j]);
		d = ft_atoi(data[j]);
		printf("d = %lld\n", d);
		add_node(list, d);
	}
	return ;
}

void	push_data_a(t_data *a, int argc, char *argv[])
{
	int	i;
	int	j;
	int flag;

	i = 0;
	flag = 0;
	while (++i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
			{
				flag = 1;
				break;
			}
			j++;
		}
		if (flag == 0)
			ft_exit("Error");
	}
	i = 0;
	while (++i < argc)
		parse_data(a, i, argv);
}

void	sort_id(t_data *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				i->id++;
			else if (i->value < j->value)
				j->id++;
			else
				ft_exit("Error\n");
			j = j->next;
		}
		i = i->next;
	}
}

int prev_sorted(t_data *a)
{
	t_node	*i;

	i = a->head;
	while (i->next)
	{
		if (i->id > i->next->id)
			return (0);
		i = i->next;
	}
	return (1);
}

void	free_nodes(t_data *list)
{
	t_node	*new;

	new = list->head;
	while (list->haed)
	{
		list->head = list->head->next;
		free(new);
		new = list->head;
	}
	list->tail = NULL;
	list->size = 0;
}

void	sand_algo(t_data *a, t_data *b)
{
	if (a->size == 2)
	else if (a->size == 3)
	else if (a->size == 4)
	else if (a->size == 5)
	else
	{
		
	}
}

int main(int argc, char *argv[])
{
	int i;
	int j;
	t_data a;
	t_data b;
	
	if (argc < 2)
		ft_exit("Error");
	init_ab(&a);
	init_ab(&b);
	push_data_a(&a, argc, argv);
	/*t_node	*t = a.head;
	printf("print all\n");
	while (t)
	{
		printf("%d\n", t->value);
		t = t->next;
	}*/
	sort_id(&a);
	if (prev_sorted(&a))
	{
		free_nodes(&a);
		free_nodes(&b);
		return (0);
	}
	sand_algo(&a, &b);
	free_nodes(&a);
	free_nodes(&b);
	return (0);
}
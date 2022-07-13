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
	while (list->head)
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
		push_swap("sa", a, b);
	else if (a->size == 3)
		size_three_sort(a);
	else if (a->size == 4)
		size_four_sort(a, b);
	else if (a->size == 5)
		size_five_sort(a, b);
	else
	{
		size_any_sort(a, b);
	}
}

void	size_three_sort(t_data *a)
{
	t_node	*new;
	t_node	*new2;
	t_node	*new3;

	new3 = a->head->id;
	new = a->head->next->id;
	new2 = a->head->next->next->id;
	if (prev_sorted(a))
		return ;
	if ((new3== new - 2) && (new3 == new2 - 1)) // 1 3 2
	{
		push_swap("sa", a, NULL);
		push_swap("ra", a, NULL);
	}
	if ((new3 == new + 1) && (new3 == new2 - 1)) // 2 1 3
		push_swap("sa", a, NULL);
	if ((new3 == new - 1) && (new3 == new2 + 1)) // 2 3 1
		push_swap("rra", a, NULL);
	if ((new3 == new + 2) && (new3 == new + 1)) // 3 1 2
		push_swap("ra", a, NULL);
	if ((new3 == new + 1) && (new3 == new + 2)) // 3 2 1
	{
		push_swap("sa", a, NULL);
		push_swap("rra", a, NULL);
	}
}

void	size_four_sort(t_data *a, t_data *b)
{
	while (a->size > 3)
	{
		if (a->head->id == 0)
		{
			push_swap("pb", a, b);
			break;
		}
		else
			push_swap("ra", a, b);
	}
	size_three_sort(a);
	push_swap("pa",a ,b);
}

void	size_five_sort(t_data *a, t_data *b) // 12
{
	while (a->size > 3)
	{
		if (a->head->id < 2)
			push_swap("pb", a, b);
		else
			push_swap("ra", a, b);
	}
	size_three_sort(a);
	while (b->size)
		push_swap("pa", a, b);
	if (a->head->id != 0)
		push_swap("sa", a, b);
}

void	size_any_sort(t_data *a, t_data *b) // 100 - 700 / 500 - 5500
{
	//chunk 설정
	int		chunk;
	int		size;
	int		num;

	num = 0;
	size = a->size;
	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	while (a->size)
	{
		if (a->head->id <= num)
		{
			push_swap("pb", a, b);
			num++;
		}
		else if (a->head->id <= num + chunk)
		{
			push_swap("pb", a, b);
			push_swap("rb", NULL, b);
			num++;
		}
		else
			choose_ra_rra(a, size);
	}
	size_any_sort_two(a, b);
	//돌면서 num보다 작거나 같으면 pb, num+chunck 보다 작거나 같으면 pb, rb, 아니면 ra or rra
}

void	choose_ra_rra(t_data *a, int size)
{
	if (a->tail->id <= size)
		push_swap("rra", a, NULL);
	else
		push_swap("ra", a, NULL);
}

void	choose_rb_rrb(t_data *b, int size)
{
	int		pos;
	t_node	*new;

	pos = 1;
	new = b->head;
	while (new->id != size)
	{
		pos++;
		new = new->next;
	}
	if (pos <= b->size / 2)
	{
		while (b->head->id != size)
			push_swap("rb", NULL, b);
	}
	else
	{
		while (b->head->id != size)
			push_swap("rrb", NULL, b);
	}
}

void	size_any_sort_two (t_data *a, t_data *b) // 100 - 700 / 500 - 5500
{
	int	size;

	while (b->size)
	{
		size = b->size - 1;
		choose_rb_rrb(b, size);
		push_swap("pa", a, b);
	}
}

void	push_swap(char *c, t_data *a, t_data *b)
{
	if (!ft_strncmp(c, "sa", 2))
		ft_swap(a);
	if (!ft_strncmp(c, "sb", 2))
		ft_swap(b);
	if (!ft_strncmp(c, "pa", 2))
		ft_push(a, b);
	if (!ft_strncmp(c, "pb", 2))
		ft_push(b, a);
	if (!ft_strncmp(c, "ra", 2))
		ft_rotate(a);
	if (!ft_strncmp(c, "rb", 2))
		ft_rotate(b);
	if (!ft_strncmp(c, "rra", 3))
		ft_rrotate(a);
	if (!ft_strncmp(c, "rrb", 3))
		ft_rrotate(b);
	ft_putstr(c);
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
	sort_id(&a);
	if (prev_sorted(&a))
	{
		free_node(&a);
		free_node(&b);
		return (0);
	}
	sand_algo(&a, &b);
	free_node(&a);
	free_node(&b);
	return (0);
}

void	free_node(t_data *list)
{
	t_node	*new;

	while (list->head)
	{
		new = list->head;
		list->head = list->head->next;
		free(new);
	}
	list->size = 0;
	list->tail = NULL;
}

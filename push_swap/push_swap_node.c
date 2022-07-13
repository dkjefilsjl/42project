#include "push_swap.h"

void	add_node(t_data *list, int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_exit("malloc Error\n");
	new->value = data;
	new->next = NULL;
	new->prev = NULL;
	new->id = 0;
	if (list->size == 0)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		new->next = NULL;
		new->prev = list->tail;
		list->tail->next = new;
		list->tail = new;
	}
	list->size++;
}

void	ft_swap(t_data *list)
{
	t_node	*new;

	if (list->size < 2)
		return ;
	new = list->head;
	list->head = new->next;
	new->next = list->head->next;
	new->prev = list->head;
	if (new->next)
		new->next->prev = new;
	else
		list->tail = new;
	list->head->prev = NULL;
	list->head->next = new;
}

void	ft_rotate (t_data *list) //rotate, rro 다시 살피기! 이거 하던 중
{
	t_node	*new;

	if (list->size < 2)
		return ;
	new = list->head;
	new->next->prev = NULL;
	list->head = new->next;
	new->prev = list->tail;
	list->tail->next = new;
	new->next = NULL;
	list->tail = new;
}

void	ft_rrotate(t_data *list)
{
	t_node	*new;

	if (list->size < 2)
		return ;
	new = list->tail;
	list->tail = new->prev;
	new->next = list->head;
	list->head->prev = new;
	list->head = new;
	new->prev = NULL;
	list->tail->next = NULL;
}

void	ft_push(t_data *to, t_data *from)
{
	t_node	*new;

	if (from->size < 1)
		return ;
	if (to->size < 1)
	{
		to->head = from->head;
		to->tail = from->head;
		from->head = from->head->next;
		from->head->prev = NULL;
		to->head->next = NULL;
		if (from->size == 1)
			from->tail = NULL;
		to->size++;
		from->size--;
	}
	else
	{
		to->size++;
		from->size--;
		new = to->head;
		new->prev = from->head;
		to->head = from->head;
		from->head = from->head->next;
		if (from->head)
			from->head->prev = NULL;
		new->prev->next = new;
	}
}
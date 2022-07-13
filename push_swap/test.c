#include <stdio.h>
#include "push_swap.h"

void	ft_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	printdq(t_data *dq)
{
	t_node *tmp = dq->head;
	printf("-----------------------------\n");
	if(tmp)
		printf("firstnode*prev = %p\n", tmp->prev);
	while(tmp)
	{
		printf("%d idx:%d\n",tmp->value,tmp->id);
		tmp = tmp->next;
	}
	printf("lastnode*next = %p\n", tmp);
	printf("dq_size = %d\ndq->head = %p\ndq->tail = %p\n",dq->size,dq->head,dq->tail);
	if(dq->head)
		printf("dqhead_data = %d\n dqtail_data = %d\n", dq->head->value, dq->tail->value);
	printf("----------------------------\n");
}

int main()
{
	t_data list;
	t_data list2;
	int d = 1, d1 = 2, d2 = 3, d3 = 4;

	list.head = NULL;
	list.tail = NULL;
	list.size = 0;
	list2.head = NULL;
	list2.tail = NULL;
	list.size = 0;
	add_node(&list, d);	
	add_node(&list, d1);	
	//add_node(&list2, d2);	
	//add_node(&list2, d3);
	printdq(&list);
	printdq(&list2);
	printf("-------------good--------");
	ft_push(&list2, &list);
	printdq(&list);
	printf("list2\n");
	printdq(&list2);

	return (0);
}

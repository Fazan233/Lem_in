//
// Created by Vladyslav USLYSTYI on 2019-03-07.
//

#include <tree.h>

int		count_ways(t_node *node, t_node *start)
{
	t_p_list	*tmp;
	int 		i;

	tmp = node->prev_list;
	if (tmp == NULL)
	{
		if (node == start)
			return (1);
		else
			return (0);
	}
	i = 0;
	while (tmp)
	{
		i = i + count_ways(tmp->node, start);
		tmp = tmp->next;
	}
	return (i);
}
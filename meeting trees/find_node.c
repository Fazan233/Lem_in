//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

t_node		*find_node(t_verticle *v, t_node *node)
{
	while (node)
	{
		if (node->v == v)
			return (node);
		node = node->next;
	}
	return (NULL);
}
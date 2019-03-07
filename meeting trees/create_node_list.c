//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

t_node		*create_node(t_verticle *v)
{
	t_node	*node;

	node = (t_node*)ft_memalloc(sizeof(t_node));
	node->v = v;
	return (node);
}

void		add_node(t_node **node, t_node *new_node)
{
	if (*node == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*node = new_node;
	}
	else
	{
		new_node->next = *node;
		(*node)->prev = new_node;
		new_node->prev = NULL;
		*node = new_node;
	}
}

t_node		*create_node_list(t_verticle *v)
{
	t_node	*node;

	node = NULL;
	while (v)
	{
		add_node(&node, create_node(v));
		v = v->next;
	}
	return (node);
}
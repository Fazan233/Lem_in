//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

t_pretend	*create_pretend(t_node *node)
{
	t_pretend	*pret;

	pret = (t_pretend*)ft_memalloc(sizeof(t_pretend));
	pret->node = node;
	return (pret);
}

void		add_pretend(t_pretend **pret, t_pretend *new_pret)
{
	if (*pret == NULL)
		*pret = new_pret;
	else
	{
		new_pret->next = *pret;
		*pret = new_pret;
	}
}

t_pretend	*create_pretend_list(t_node *node, int color, t_edge *edge)
{
	t_pretend	*pret;
	t_verticle	*vert;
	t_node		*tmp;

	pret = NULL;
	while (edge)
	{
		if (edge->a == node->v || edge->b == node->v)
		{
			vert = node->v == edge->a ? edge->b : edge->a;
			if (vert->color != color)
			{
				tmp = find_node(vert, node);
				add_pretend(&pret, create_pretend(tmp));
			}
		}
		edge = edge->next;
	}
	return (pret);
}
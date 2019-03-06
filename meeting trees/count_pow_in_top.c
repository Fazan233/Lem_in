//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

void		count_pow_in_top_nodes(t_top_nodes *top, int color)
{
	int 		i;
	t_pretend	*pret;

	while (top)
	{
		i = 0;
		pret = top->pretend;
		while (pret)
		{
			if (pret->node->v->color != color && pret->node->v->color != FOUND)
				i++;
			pret = pret->next;
		}
		top->pow = i;
		top = top->next;
	}
}

t_top_nodes	*get_min_pow_top_node(t_top_nodes *top)
{
	t_top_nodes	*min;

	min = top;
	while (top)
	{
		if (min->pow > top->pow)
			min = top;
		top = top->next;
	}
	return (min);
}
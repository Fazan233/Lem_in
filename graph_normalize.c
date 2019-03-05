//
// Created by Vladyslav USLYSTYI on 2019-03-01.
//

#include "lem_in.h"

t_edge	*get_once_link(t_edge *edge, t_verticle *v)
{
	int 	i;
	t_edge	*find;

	i = 0;
	while (edge)
	{
		if (edge->a == v || edge->b == v)
		{
			i++;
			find = edge;
			if (i > 1)
				return (NULL);
		}
		edge = edge->next;
	}
	if (i == 0)
		return (NULL);
	return (find);
}

void	delete_vert_link(t_lemin *lem, t_verticle *v)
{
	if (v)
	{
		if (v->prev)
			v->prev->next = v->next;
		else
			lem->vert = v->next;
		if (v->next)
			v->next->prev = v->prev;
		free(v);
	}
}

void	delete_edge_link(t_lemin *lem, t_edge *edge)
{
	if (edge->prev)
		edge->prev->next = edge->next;
	else
		lem->graph = edge->next;
	if (edge->next)
		edge->next->prev = edge->prev;
	free(edge);
}

void 	graph_normalize(t_lemin *lem)
{
	t_edge		*edge;
	t_verticle	*v;
	t_edge 		*tmp;
	int 		op;

	v = lem->vert;
	while (1)
	{
		op = 1;
		while (v)
		{
			edge = lem->graph;
			if ((tmp = get_once_link(edge, v)))
			{
				delete_edge_link(lem, tmp);
				v = v->next;
				delete_vert_link(lem, v->prev);
				op = 0;
			}
			v = v->next;
		}
		if (op == 1)
			break ;
	}
}
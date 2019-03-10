//
// Created by Vladyslav USLYSTYI on 2019-03-07.
//

#include <lem_in.h>

void	del_edge(t_edge **orig_edge, t_edge *edge)
{
	if (edge == *orig_edge)
	{
		*orig_edge = (*orig_edge)->next;
		(*orig_edge)->prev = NULL;
	}
	else
	{
		if (edge->prev)
			edge->prev->next = edge->next;
		if (edge->next)
			edge->next->prev = edge->prev;
	}
	free(edge);
}

void	del_vert(t_verticle **orig_v, t_verticle *v)
{
	if (v == *orig_v)
	{
		*orig_v = (*orig_v)->next;
		(*orig_v)->prev = NULL;
	}
	else
	{
		if (v->prev)
			v->prev->next = v->next;
		if (v->next)
			v->next->prev = v->prev;
	}
	free(v);
}

int		del_single(t_edge **orig_edge, t_verticle **orig_v)
{
	t_verticle	*v;
	int 	count;
	t_edge	*edge;
	t_edge	*tmp;
	t_verticle	*v_tmp;
	int 	i;

	count = 0;
	v = *orig_v;
	while (v)
	{
		i = 0;
		v_tmp = v->next;
		edge = *orig_edge;
		while (edge)
		{
			if (edge->a == v || edge->b == v)
			{
				tmp = edge;
				i++;
			}
			edge = edge->next;
		}
		if (i == 1 && (++count))
		{
			del_edge(orig_edge, tmp);
			del_vert(orig_v, v);
		}
		v = v_tmp;
	}
	return (count);
}
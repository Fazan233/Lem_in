//
// Created by Vladyslav USLYSTYI on 2019-02-21.
//

#include "lem_in.h"
#define BELONG_TO_EDGE (curr_vert == edge->a || curr_vert == edge->b)
#define GET_OTHER_VERT(curr, edge) curr == edge->a ? edge->b : edge->a

void	set_begin_vals(t_verticle **v, t_lemin *lem, t_edge **edge)
{
	t_verticle	*begin = *v;
	while (begin != NULL)
	{
		begin->weight = INF;
		begin->short_way = NULL;
		begin = begin->next;
	}
	lem->start_vert->weight = 0;
	if (lem->start_vert->prev)
	{
		lem->start_vert->prev->next = lem->start_vert->next;
		if (lem->start_vert->next)
			lem->start_vert->next->prev = lem->start_vert->prev;
		lem->start_vert->next = *v;
		lem->start_vert->prev = NULL;
		(*v)->prev = lem->start_vert; //kostyl
	}
	*edge = lem->graph;
	*v = lem->start_vert;
}
// take second elem of list!!
void	dijkstra_sort(t_verticle *v)
{
	t_verticle	*tmp;

	if (!v)
		return ;
	while (v && v->prev && v->weight >= v->prev->weight)
		v = v->next;
	tmp = v->prev;
	if (v)
		while (tmp && tmp->prev)
		{
			if (tmp->weight <= v->weight)
			{
				swap_2link_item(&tmp, &v);
				return ;
			}
			tmp = tmp->prev;
		}
}

t_way	*get_short_way(t_lemin *lem)
{
	t_way		*way;
	t_verticle	*v;

	way = NULL;
	v = lem->end_vert;
	if (v->short_way == NULL)
		return (NULL);
	while (1)
	{
		add_new_vert_to_way(&way, v);
		if (v->short_way == NULL)
			break ;
		else
			v = GET_OTHER_VERT(v, v->short_way);
	}
	return (way);
}

t_way	*dijkstra(t_verticle *v, t_lemin *lem)
{
	t_verticle	*curr_vert;
	t_verticle	*other_vert;
	t_edge		*edge;

	set_begin_vals(&v, lem, &edge);
	while (1)
	{
		curr_vert = get_min_vert(lem->start_vert);
		if (curr_vert == lem->end_vert || curr_vert == NULL)
			break ;
		while (edge)
		{
			if (edge->available && BELONG_TO_EDGE &&
				(other_vert = GET_OTHER_VERT(curr_vert, edge)) &&
				curr_vert->weight + 1 < other_vert->weight)
			{
				other_vert->weight = curr_vert->weight + 1;
				dijkstra_sort(v->next);
				other_vert->short_way = edge;
			}
			edge = edge->next;
		}
	}
	return (get_short_way(lem));
}
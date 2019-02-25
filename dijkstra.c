//
// Created by Vladyslav USLYSTYI on 2019-02-21.
//

#include "lem_in.h"
#define BELONG_TO_EDGE (curr_vert == edge->a || curr_vert == edge->b)
#define GET_OTHER_VERT(curr, edge) curr == edge->a ? edge->b : edge->a

void	set_begin_vals(t_verticle **v, t_lemin *lem)
{
	t_verticle *begin;

	begin = *v;
	while (begin != NULL)
	{
		begin->weight = INF;
		begin->short_way = NULL;
		begin = begin->next;
	}
	lem->start_vert->weight = 0;
}
// take second elem of list!!
void	dijkstra_sort(t_verticle *v)
{
	t_verticle	*tmp;

	while (v && v->weight >= v->prev->weight)
		v = v->next;
	if (!v)
		return ;
	tmp = v->prev;
		while (tmp)
		{
			if (tmp->weight <= v->weight)
			{
				swap_2link_item(tmp->next, v);
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
		if (v == lem->end_vert)
			way->short_way = NULL;
		else
			way->short_way = way->next->vert->short_way;
		if (v->short_way == NULL)
			break ;
		else
			v = GET_OTHER_VERT(v, v->short_way);
	}
	return (way);
}


t_edge	*put_egle_in_order(t_edge **edge, t_verticle *v)
{
	t_edge	*iter;
	t_edge	*tmp;
	t_edge	*start;

	start = *edge;
	iter = *edge;
	if (start)
		while (iter)
		{
			if (iter->a == v || iter->b == v)
			{
				tmp = iter;
				iter = iter->next;
				if (tmp->prev)
					tmp->prev = tmp->next;
				if (tmp->next)
					tmp->next = tmp->prev;
				tmp->next = start;
				tmp->prev = start->prev;
				start->prev = tmp;
				start = tmp;
				continue ;
			}
			iter = iter->next;
		}
	return (start);
}


//t_way	*dijkstra(t_lemin *lem)
//{
//	t_verticle	*curr_vert;
//	t_verticle	*other_vert;
//	t_edge		*edge;
//	int			i;
//
//	i = 0;
//	set_begin_vals(&lem->vert, lem);
//	while (1)
//	{
//		ft_printf("%d ", i++);
//		curr_vert = get_min_vert(lem->start_vert, lem);
//		if (curr_vert == lem->end_vert || curr_vert == NULL)
//			break ;
//		edge = lem->graph;
//		while (edge)
//		{
//			if (edge->available && BELONG_TO_EDGE &&
//			(other_vert = GET_OTHER_VERT(curr_vert, edge)) &&
//			other_vert->light && curr_vert->weight + 1 < other_vert->weight)
//			{
//				other_vert->weight = curr_vert->weight + 1;
//				dijkstra_sort(lem->vert->next);
//				other_vert->short_way = edge;
//			}
//			edge = edge->next;
//		}
//	}
//	ft_printf("\n");
//	return (get_short_way(lem));
//}


t_way	*dijkstra(t_lemin *lem)
{
	t_verticle	*curr_vert;
	t_verticle	*other_vert;
	t_edge		*edge_end;
	t_edge		*edge_start;
	t_edge		*tmp;
	int			i;

	i = 0;
	set_begin_vals(&lem->vert, lem);

	edge_start = lem->graph;
	edge_end = edge_start;
	while (1)
	{
		ft_printf("%d ", i++);

		curr_vert = get_min_vert(lem->start_vert, lem);
		tmp = put_egle_in_order(&edge_end, curr_vert);
		edge_start = tmp;
		if (curr_vert == lem->end_vert || curr_vert == NULL)
			break ;
		while (edge_start != edge_end)
		{
			if (edge_start->available &&
				(other_vert = GET_OTHER_VERT(curr_vert, edge_start)) &&
				other_vert->light && curr_vert->weight + 1 < other_vert->weight)
			{
				other_vert->weight = curr_vert->weight + 1;
				dijkstra_sort(lem->vert->next);
				other_vert->short_way = edge_start;
			}
			edge_start = edge_start->next;
		}
	}
	ft_printf("\n");
	return (get_short_way(lem));
}
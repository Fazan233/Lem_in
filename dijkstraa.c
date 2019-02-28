//
// Created by Vladyslav USLYSTYI on 2019-02-28.
//

#include "lem_in.h"
#define GET_OTHER_VERT(curr, edge) curr == edge->a ? edge->b : edge->a

void	set_begin_vals(t_verticle *begin, t_lemin *lem)
{
	while (begin != NULL)
	{
		begin->used = 0;
		begin->weight = INF;
		begin->short_way = NULL;
		begin = begin->next;
	}
	lem->start_vert->weight = 0;
}
// take second elem of list!!
//void	dijkstra_sort(t_verticle *v)
//{
//	t_verticle	*tmp;
//
//	while (v && v->weight >= v->prev->weight)
//		v = v->next;
//	if (!v)
//		return ;
//	tmp = v->prev;
//		while (tmp)
//		{
//			if (tmp->weight <= v->weight)
//			{
//				swap_2link_item(tmp->next, v);
//				return ;
//			}
//			tmp = tmp->prev;
//		}
//}




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


//t_edge	*put_egle_in_order(t_edge **edge, t_verticle *v)
//{
//	t_edge	*iter;
//	t_edge	*tmp;
//	t_edge	*start;
//
//	start = *edge;
//	iter = *edge;
//	if (start)
//	{
//		if (start->a == v || start->b == v)
//		{
//			*edge = (*edge)->next;
//			iter = iter->next;
//		}
//		while (iter)
//		{
//			if (iter->a == v || iter->b == v)
//			{
//				tmp = iter;
//				iter = iter->next;
//				if (tmp->prev)
//					tmp->prev->next = tmp->next;
//				if (tmp->next)
//					tmp->next->prev = tmp->prev;
//				tmp->next = start;
//				tmp->prev = start->prev;
//				if (start->prev)
//					start->prev->next = tmp;
//				start->prev = tmp;
//				start = tmp;
//				continue ;
//			}
//			iter = iter->next;
//		}
//	}
//	return (start);
//}


//t_way	*dijkstra(t_lemin *lem)
//{
//	t_verticle	*curr_vert;
//	t_verticle	*other_vert;
//	t_edge		*edge;
//
//	set_begin_vals(&lem->vert, lem);
//	while (1)
//	{
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
//	return (get_short_way(lem));
//}


t_list_e	*find_list_e(t_list_v *list_v, t_verticle *v)
{
	if (v)
	{
		while (list_v)
		{
			if (list_v->v == v)
				return (list_v->list_e);
			list_v = list_v->next;
		}
	}
	return (NULL);
}

void	paste_a_after_b(t_verticle *a, t_verticle *b)
{
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->next = a;
	a->prev = b;
}

void	paste_a_before_b(t_verticle *a, t_verticle *b)
{
	if (b->prev)
		b->prev->next = a;
	a->prev = b->prev;
	a->next = b;
	b->prev = a;
}
// b - before, a - after

void	for_paste_sort(t_verticle *elem)
{
	if (elem->next)
		elem->next->prev = elem->prev;
	elem->prev->next = elem->next;
}

void	paste_and_sort(t_verticle *elem, char mode)
{
	t_verticle	*v;

	v = mode == 'b' ? elem->next : elem->prev;
	if (mode == 'b')
		while (v)
		{
			if (v->weight >= elem->weight)
			{
				for_paste_sort(elem);
				paste_a_before_b(elem, v);
				break ;
			}
			v = v->next;
		}
	else
		while (v)
		{
			if (elem->weight >= v->weight)
			{
				for_paste_sort(elem);
				paste_a_after_b(elem, v);
				break ;
			}
			v = v->prev;
		}
}

void	dijkstra_sort(t_verticle *elem)
{
	if (elem->next)
	{
		if (elem->weight > elem->prev->weight &&
			elem->weight > elem->next->weight)
			paste_and_sort(elem, 'b');
		else if (elem->weight < elem->prev->weight &&
				 elem->weight < elem->next->weight)
			paste_and_sort(elem, 'a');
	}
	else if (elem->prev->weight > elem->weight)
		paste_and_sort(elem, 'a');
}

t_way	*dijkstra(t_lemin *lem)
{
	t_verticle	*curr_vert;
	t_verticle	*other_vert;
	t_list_e	*list_e;

	set_begin_vals(lem->vert, lem);
	while (1)
	{
		curr_vert = get_min_vert(lem->start_vert);
		list_e = find_list_e(lem->list_v, curr_vert);
		if (curr_vert == lem->end_vert || curr_vert == NULL)
			break ;
		while (list_e)
		{
			if (list_e->e->available &&
				(other_vert = GET_OTHER_VERT(curr_vert, list_e->e)) &&
				other_vert->light && curr_vert->weight + 1 < other_vert->weight)
			{
				other_vert->weight = curr_vert->weight + 1;
				dijkstra_sort(other_vert);
				other_vert->short_way = list_e->e;
			}
			list_e = list_e->next;
		}
	}
	return (get_short_way(lem));
}

t_verticle		*get_min_vert(t_verticle *v)
{
	while (v)
	{
		if (v->used == 0)
		{
			if (v->weight != INF)
			{
				v->used = 1;
				return (v);
			}
			break ;
		}
		v = v->next;
	}
	return (NULL);
}
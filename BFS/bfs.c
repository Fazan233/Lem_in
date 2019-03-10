//
// Created by Vladyslav USLYSTYI on 2019-03-08.
//

#include "bfs.h"
#define GET_OTHER_VERT(curr, edge) curr == edge->a ? edge->b : edge->a

static void	set_begin_vals(t_verticle *begin, t_queue **queue,
							t_verticle *start_from)
{
	while (begin != NULL)
	{
		begin->gray = 0;
		begin->visited = 0;
		begin->weight = 0;
		begin->short_way = NULL;
		begin = begin->next;
	}
	*queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	push_queue(*queue, start_from);
}

t_way		*bfs_s(t_lemin *lem)
{
	t_queue		*queue;
	t_verticle	*curr_v;
	t_list_e	*list_e;
	t_verticle	*other;

	set_begin_vals(lem->vert, &queue, lem->start_vert);
	while (queue->last)
	{
		curr_v = pop_queue(queue);
		if (curr_v == lem->end_vert)
			break ;
		curr_v->visited = 1;
//		list_e = find_list_e(lem->list_v, curr_v);
		list_e = lem->list_v[curr_v->n].list_e;
		while (list_e)
		{
			other = GET_OTHER_VERT(curr_v, list_e->e);
			if (list_e->e->available && other->gray == 0 && other->visited == 0)
			{
				other->gray = 1;
				other->short_way = list_e->e;
				other->weight = curr_v->weight + 1;
				push_queue(queue, other);
			}
			list_e = list_e->next;
		}
	}
	return (get_short_way_s(lem));
}

t_way		*bfs_e(t_lemin *lem)
{
	t_queue		*queue;
	t_verticle	*curr_v;
	t_list_e	*list_e;
	t_verticle	*other;

	set_begin_vals(lem->vert, &queue, lem->end_vert);
	while (queue->last)
	{
		curr_v = pop_queue(queue);
		if (curr_v == lem->start_vert)
			break ;
		curr_v->visited = 1;
		list_e = lem->list_v[curr_v->n].list_e;
		while (list_e)
		{
			other = GET_OTHER_VERT(curr_v, list_e->e);
			if (list_e->e->available && other->gray == 0 && other->visited == 0)
			{
				other->gray = 1;
				other->short_way = list_e->e;
				other->weight = curr_v->weight + 1;
				push_queue(queue, other);
			}
			list_e = list_e->next;
		}
	}
	return (get_short_way_e(lem));
}



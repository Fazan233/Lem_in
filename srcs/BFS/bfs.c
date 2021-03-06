/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:43:59 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/20 11:30:41 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define GET_OTHER_VERT(curr, edge) curr == edge->a ? edge->b : edge->a

static void		set_begin_vals(t_verticle *begin, t_queue *queue,
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
	ft_bzero(queue, sizeof(t_queue));
	push_queue(queue, start_from);
}

static void		push_vert_in_queue(t_list_e *list_e, t_verticle *other,
								t_verticle *curr_v, t_queue *queue)
{
	if (list_e->e->available && other->gray == 0 && other->visited == 0
		&& other->block == 0)
	{
		other->gray = 1;
		other->short_way = list_e->e;
		other->weight = curr_v->weight + 1;
		push_queue(queue, other);
	}
}

t_way			*bfs(t_lemin *lem)
{
	t_verticle	*curr_v;
	t_list_e	*list_e;
	t_verticle	*other;

	ft_bzero(&lem->queue, sizeof(t_queue));
	set_begin_vals(lem->vert, &lem->queue, lem->start_vert);
	while (lem->queue.last)
	{
		curr_v = pop_queue(&lem->queue);
		if (curr_v == lem->end_vert)
		{
			del_queue_list(&lem->queue);
			break ;
		}
		curr_v->visited = 1;
		list_e = lem->list_v[curr_v->n].list_e;
		while (list_e)
		{
			other = GET_OTHER_VERT(curr_v, list_e->e);
			push_vert_in_queue(list_e, other, curr_v, &lem->queue);
			list_e = list_e->next;
		}
	}
	return (get_short_way(lem));
}

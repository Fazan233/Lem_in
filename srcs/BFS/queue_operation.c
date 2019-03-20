/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:45:18 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:46:35 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_qlist		*create_qlist(t_verticle *v)
{
	t_qlist		*qlist;

	qlist = (t_qlist*)ft_memalloc(sizeof(t_qlist));
	qlist->v = v;
	return (qlist);
}

void		push_queue(t_queue *queue, t_verticle *v)
{
	t_qlist		*qlist;

	qlist = create_qlist(v);
	if (queue->qlist == NULL)
	{
		queue->qlist = qlist;
		queue->last = qlist;
	}
	else
	{
		qlist->next = queue->qlist;
		queue->qlist->prev = qlist;
		queue->qlist = qlist;
	}
}

t_verticle	*pop_queue(t_queue *queue)
{
	t_verticle	*v;
	t_qlist		*tmp;

	v = NULL;
	if (queue->last)
	{
		v = queue->last->v;
		if (queue->last->prev)
			queue->last->prev->next = NULL;
		else
		{
			free(queue->qlist);
			queue->qlist = NULL;
			queue->last = NULL;
			return (v);
		}
		tmp = queue->last->prev;
		free(queue->last);
		queue->last = tmp;
	}
	return (v);
}

void		del_queue_list(t_queue *queue)
{
	t_qlist		*tmp;

	if (queue->qlist)
	{
		while (queue->qlist->next)
		{
			tmp = queue->qlist;
			queue->qlist = queue->qlist->next;
			free(tmp);
		}
		free(queue->qlist);
	}
}

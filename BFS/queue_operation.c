//
// Created by Vladyslav USLYSTYI on 2019-03-08.
//

#include "bfs.h"

t_qlist		*create_qlist(t_verticle *v)
{
	t_qlist	*qlist;

	qlist = (t_qlist*)ft_memalloc(sizeof(t_qlist));
	qlist->v = v;
	return (qlist);
}

void		push_queue(t_queue *queue, t_verticle *v)
{
	t_qlist	*qlist;

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
			queue->qlist = NULL;
		tmp = queue->last->prev;
		free(queue->last);
		queue->last = tmp;
	}
	return (v);
}
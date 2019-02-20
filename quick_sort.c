//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#include "lem_in.h"


void		set_start_finish(t_verticle **start, t_verticle **finish,
								t_partition *p)
{
	if (*start == p->target)
		*start = p->iter;
	else if (*start == p->iter)
		*start = p->target;
	if (*finish == p->target)
		*finish = p->iter;
	else if (*finish == p->iter)
		*finish = p->target;
	p->opt = !p->opt;
}

t_verticle	*partition(t_verticle **start, t_verticle **finish, t_partition *p)
{
	if (p->target->weight > p->iter->weight && p->target->prev == p->iter)
	{
		set_start_finish(start, finish, p);
		swap_2link_item(&p->iter, &p->target);
	}
	while (1)
	{
		if (p->target == p->iter)
			break;
		else if (p->opt && p->target->weight > p->iter->weight)
		{
			set_start_finish(start, finish, p);
			swap_2link_item(&p->target, &p->iter);
		}
		else if (!p->opt && p->target->weight < p->iter->weight)
		{
			set_start_finish(start, finish, p);
			swap_2link_item(&p->iter, &p->target);
		}
		p->iter = p->opt ? p->iter->prev : p->iter->next;
	}
	return (p->target);
}

t_verticle	*quick_sort(t_verticle *start, t_verticle *finish)
{
	t_verticle	*elem;
	t_verticle	*begin;
	t_partition	p;

	p.target = start;
	p.iter = finish;
	p.opt = 1;
	begin = start;
	if (start->next == finish && start->prev == finish &&
		start->weight > finish->weight)
		return (finish);
	elem = partition(&start, &finish, &p);
	if (elem != start)
		begin = quick_sort(start, elem->prev);
	if (elem != finish)
		quick_sort(elem->next, finish);
	return (begin);
}
//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#include "lem_in.h"

t_verticle	*partition(t_verticle **start, t_verticle **finish)
{
	t_verticle	*target;
	t_verticle	*iter;
	int			opt;

	target = *start;
	iter = *finish;
	opt = 1;
	while (1)
	{
		if (target == iter)
			break;
		if (opt)
		{
			if (target->weight > iter->weight)
			{
				if (*start == target)
					*start = iter;
				else if (*start == iter)
					*start = target;
				if (*finish == target)
					*finish = iter;
				else if (*finish == iter)
					*finish = target;
				swap_2link_item(&target, &iter);
				opt = !opt;
			}
		}
		else
			if (target->weight < iter->weight)
			{
				if (*start == target)
					*start = iter;
				else if (*start == iter)
					*start = target;
				if (*finish == target)
					*finish = iter;
				else if (*finish == iter)
					*finish = target;
				swap_2link_item(&iter, &target);
				opt = !opt;
			}
		if (opt)
			iter = iter->prev;
		else
			iter = iter->next;
	}
	return (target);
}

void		quick_sort(t_verticle *start, t_verticle *finish)
{
	t_verticle	*elem;

	elem = partition(&start, &finish);
	if (elem != start)
		quick_sort(start, elem->prev);
	if (elem != finish)
		quick_sort(elem->next, finish);
}
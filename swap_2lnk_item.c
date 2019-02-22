//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#include "lem_in.h"

void		swap_pointer(t_verticle **a, t_verticle **b)
{
	t_verticle	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_2link_item(t_verticle **a, t_verticle **b)
{
	if ((*a)->prev)
		(*a)->prev->next = *b;
	if ((*a)->next)
		(*b)->next->prev = *a;
	if ((*a)->next == *b || (*a)->prev == *b)
	{
		swap_pointer(&(*a)->prev, &(*b)->next);
		swap_pointer(&(*a)->next, &(*a)->prev);
		swap_pointer(&(*b)->next, &(*b)->prev);
	}
	else
	{
		(*a)->next->prev = *b;
		(*b)->prev->next = *a;
		swap_pointer(&(*a)->next, &(*b)->next);
		swap_pointer(&(*a)->prev, &(*b)->prev);
	}
}
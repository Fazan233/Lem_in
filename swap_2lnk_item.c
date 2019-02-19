//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#include "lem_in.h"

static void	swap_pointer(t_verticle **a, t_verticle **b)
{
	t_verticle	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_2link_item(t_verticle **a, t_verticle **b)
{
	t_verticle	*tmp;

	if ((*a)->next == *b || (*a)->prev == *b)
	{
		tmp = (*a)->prev;
		(*a)->prev->next = *b;
		(*b)->next->prev = *a;
		(*a)->prev = *b;
		(*a)->next = (*b)->next;
		(*b)->prev = tmp->next;
		(*b)->next = *a;
	}
	else
	{
		//	if ((*a)->prev->next != *b)
		(*a)->prev->next = *b;
//	if ((*a)->next->prev != *b)
		(*a)->next->prev = *b;
//	if ((*b)->prev->next != *a)
		(*b)->prev->next = *a;
//	if ((*b)->next->prev != *a)
		(*b)->next->prev = *a;
		swap_pointer(&(*a)->next, &(*b)->next);
		swap_pointer(&(*a)->prev, &(*b)->prev);
	}
}
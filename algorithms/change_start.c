//
// Created by Vladyslav USLYSTYI on 2019-03-10.
//

#include "lem_in.h"

void		change_start(t_ways **start, int shift)
{
	t_ways	*end;

	end = *start;
	while (end->next)
		end = end->next;
	end->next = *start;
	while (shift-- > 0)
		*start = (*start)->next;
	end = *start;
	while (end->next != *start)
		end = end->next;
	end->next = NULL;
}
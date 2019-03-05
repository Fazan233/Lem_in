//
// Created by Vladyslav USLYSTYI on 2019-03-01.
//

#include "lem_in.h"

static void	firstswap(t_ways **begin)
{
	t_ways	*tmp;

	tmp = (*begin)->next;
	(*begin)->next = tmp->next;
	tmp->next = *begin;
	*begin = tmp;
}

static void	secondswap(t_ways *list)
{
	t_ways	*first;
	t_ways	*second;

	first = list->next;
	second = list->next->next;
	list->next = second;
	first->next = second->next;
	list->next->next = first;
}

static int	list_size(t_ways *ways)
{
	int i;

	i = 0;
	while (ways)
	{
		i++;
		ways = ways->next;
	}
	return (i);
}

void		bubble_sort_list(t_ways **begin)
{
	t_ways	*t;
	int		len;
	int		i;

	len = list_size(*begin);
	while (len >= 2)
	{
		i = 0;
		while (++i < len)
		{
			if (i == 1 && (*begin)->len > (*begin)->next->len)
				firstswap(begin);
			if (i == 2)
				t = *begin;
			if (i >= 2)
			{
				if (t->next->len > t->next->next->len)
					secondswap(t);
				t = t->next;
			}
		}
		len--;
	}
}
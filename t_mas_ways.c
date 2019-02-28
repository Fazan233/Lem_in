//
// Created by Vladyslav USLYSTYI on 2019-02-23.
//

#include "lem_in.h"

void		add_to_mas_ways(t_mas_ways **mas_ways, t_ways *ways)
{
	t_mas_ways	*tmp;
	t_mas_ways	*t;

	tmp = (t_mas_ways*)malloc(sizeof(t_mas_ways));
	if (tmp)
	{
		tmp->ways = ways;
		tmp->iter = 0;
		tmp->lst_lens = NULL;
		tmp->next = NULL;
		if (*mas_ways == NULL)
			*mas_ways = tmp;
		else
		{
			t = *mas_ways;
			while (t->next)
				t = t->next;
			t->next = tmp;
		}
	}
}

void		get_mas_ways(t_lemin *lem)
{
	t_ways		*ways;

	while ((ways = find_list_ways(lem, lem->mas_ways)))
		add_to_mas_ways(&lem->mas_ways, ways);
	get_iters(lem->mas_ways, lem);
}
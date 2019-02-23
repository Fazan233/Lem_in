//
// Created by Vladyslav USLYSTYI on 2019-02-23.
//

#include "lem_in.h"

void		add_to_mas_ways(t_mas_ways **mas_ways, t_ways *ways)
{
	t_mas_ways	*tmp;

	tmp = (t_mas_ways*)malloc(sizeof(t_mas_ways));
	if (tmp)
	{
		tmp->ways = ways;
		tmp->iter = 0;
		if (*mas_ways == NULL)
		{
			tmp->next = NULL;
			*mas_ways = tmp;
		}
		else
		{
			tmp->next = *mas_ways;
			*mas_ways = tmp;
		}
	}
	else
	{
		ft_printf(ERROR_ALLOCATE);
		exit(1);
	}
}

void		get_mas_ways(t_lemin *lem)
{
	t_ways		*ways;
	t_mas_ways	*mas_ways;

	mas_ways = NULL;
	while ((ways = find_list_ways(lem, mas_ways)))
		add_to_mas_ways(&mas_ways, ways);
	lem->mas_ways = mas_ways;
}
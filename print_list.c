//
// Created by User on 19.02.2019.
//

#include "lem_in.h"

void	print_list(t_verticle *start, t_verticle *end)
{
	while (start != end)
	{
		ft_printf("%d ", start->weight);
		start = start->next;
	}
	ft_printf("%d\n", end->weight);
}

void	print_way(t_way *way)
{
	t_way	*end;

	if (way)
	{
		end = way->prev;
		while (1)
		{
			if (way == end)
			{
				ft_printf("{RED}%s{EOC}\n", way->vert->name);
				break ;
			}
			if (way == end->next)
				ft_printf("{GREEN}%s{EOC} -> ", way->vert->name);
			else
				ft_printf("%s -> ", way->vert->name);
			way = way->next;
		}
	}
	else
		ft_printf("The way is not exist\n");
}

void	print_ways(t_ways *ways)
{
	if (ways)
	{
		while (ways)
		{
			print_way(ways->way);
			ways = ways->next;
		}
	}
	else
		ft_printf("The ways is not exist\n");
}
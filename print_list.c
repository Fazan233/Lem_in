//
// Created by User on 19.02.2019.
//

#include "lem_in.h"

void	print_list(t_verticle *start, t_verticle *end)
{
	int	i;

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
				break;
			}
			if (way == end->next)
				ft_printf("{GREEN}%s{EOC} -> ", way->vert->name);
			else
				ft_printf("%s -> ", way->vert->name);
			way = way->next;
		}
	}
	ft_printf("The way is not exist\n");
}
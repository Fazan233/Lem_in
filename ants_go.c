//
// Created by Vladyslav USLYSTYI on 2019-03-13.
//

#include "lem_in.h"

void	go_ants_in_way(t_way *way, t_lemin *lem, int *steps, int *ant)
{
	t_way	*end;

	end = way->prev;
	while (end->prev != way)
	{
		if (end->prev->ant)
		{
			ft_printf("L%d-%s ", end->prev->ant, end->vert->name);
			end->ant = end->prev->ant;
			end->prev->ant = 0;
			(*steps)++;
		}
		end = end->prev;
	}
	if (lem->ants)
	{
		ft_printf("L%d-%s ", ++(*ant), end->vert->name);
		end->ant = *ant;
		lem->ants--;
		(*steps)++;
	}
}

void	ants_go(t_ways *ways, t_lemin *lem)
{
	t_ways	*begin;
	int 	steps;
	int 	tmp;
	int 	ant;

	ant = 0;
	steps = 1;
	begin = ways;
	while (steps)
	{
		steps = 0;
		ways = begin;
		while (ways)
		{
			tmp = number_can_way(ways, begin);
			if (lem->ants >= tmp)
				go_ants_in_way(ways->way, lem, &steps, &ant);
			else
				break ;
			ways = ways->next;
		}
		ft_printf("\b\n");
	}
}

void	ants_go_one_way(t_lemin *lem)
{
	int 	ants;

	ants = 1;
	while (ants <= lem->ants)
	{
		ft_printf("L%d-%s ", ants, lem->end_vert->name);
		ants++;
	}
	ft_printf("\b\n");
	system("leaks -q Lem_in");
	exit(0);
}
//
// Created by Vladyslav USLYSTYI on 2019-03-14.
//

#include "lem_in.h"

static void	p_go_ants_in_way(t_way *way, t_lemin *lem, int *steps, int *ant)
{
	t_way	*end;

	end = way->prev;
	while (end->prev != way)
	{
		if (end->prev->ant)
		{
			end->ant = end->prev->ant;
			end->prev->ant = 0;
			(*steps)++;
		}
		end = end->prev;
	}
	if (lem->ants)
	{
		lem->list_ants[*ant].way = way;
		++(*ant);
		end->ant = *ant;
		lem->ants--;
		(*steps)++;
	}
}

static void	p_ants_go_one_way(t_lemin *lem)
{
	int 	ants;

	lem->mas_res->mas_ways->iter = 1;
	ants = 1;
	while (ants <= lem->ants)
	{
		lem->list_ants[ants - 1].way = lem->mas_res->mas_ways->ways->way;
		ants++;
	}
}

void	p_ants_go(t_ways *ways, t_lemin *lem, int ant)
{
	t_ways	*begin;
	int 	steps;

	if (ways->way->next->vert == lem->end_vert)
		p_ants_go_one_way(lem);
	else
	{
		ant = 0;
		steps = 1;
		begin = ways;
		while (steps)
		{
			steps = 0;
			ways = begin;
			while (ways)
			{
				if (lem->ants >= number_can_way(ways, begin))
					p_go_ants_in_way(ways->way, lem, &steps, &ant);
				else
					break ;
				ways = ways->next;
			}
		}
	}
}

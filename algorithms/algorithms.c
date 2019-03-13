//
// Created by Vladyslav USLYSTYI on 2019-03-10.
//

#include "lem_in.h"
#include "lem_algos.h"

void		algorithm(t_lemin *lem, int shift)
{
	t_ways		*ways;

	while ((ways = find_list_ways(lem, lem->mas_ways)))
	{
		change_start(&ways, shift);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
}
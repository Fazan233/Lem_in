//
// Created by Vladyslav USLYSTYI on 2019-03-10.
//

#include "lem_in.h"
#include "lem_algos.h"

void		algorithm1(t_lemin *lem, int algo)
{
	t_ways		*ways;

	while (algo == 1 && (ways = find_list_ways_s(lem, lem->mas_ways)))
	{
		bubble_sort_list_l_u(&ways);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
	while (algo == 2 && (ways = find_list_ways_s(lem, lem->mas_ways)))
	{
		bubble_sort_list_u_l(&ways);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
	while (algo == 3 && (ways = find_list_ways_e(lem, lem->mas_ways)))
	{
		bubble_sort_list_l_u(&ways);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
	while (algo == 4 && (ways = find_list_ways_e(lem, lem->mas_ways)))
	{
		bubble_sort_list_u_l(&ways);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
}

void		algorithm2(t_lemin *lem, int shift)
{
	t_ways		*ways;

	while ((ways = find_list_ways_s(lem, lem->mas_ways)))
	{
		change_start(&ways, shift);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
}
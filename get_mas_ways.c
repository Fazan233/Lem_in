//
// Created by Vladyslav USLYSTYI on 2019-02-23.
//

#include <time.h>
#include "lem_in.h"

//void		get_mas_ways(t_lemin *lem)
//{
//	t_ways		*ways;
//	int 		i;
//
//	i = 20;
//	while (i >= 0)
//	{
//		(ways = find_list_ways2(lem, lem->mas_ways));
////		bubble_sort_list_l_u(&ways);
//		bubble_sort_list_u_l(&ways);
//		add_to_mas_ways(&lem->mas_ways, ways);
//		i--;
//	}
//}

void		get_mas_ways(t_lemin *lem)
{
	t_ways		*ways;

	while ((ways = find_list_ways_e(lem, lem->mas_ways)))
	{
//		change_start(&ways, 4);
		bubble_sort_list_l_u(&ways);
//		bubble_sort_list_u_l(&ways);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
}
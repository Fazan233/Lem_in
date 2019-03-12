//
// Created by Vladyslav USLYSTYI on 2019-03-10.
//

#include "lem_in.h"
#include "lem_algos.h"
#define	TO 6

t_mas_ways		*get_min_mas_ways(t_mas_ways *mas_ways)
{
	t_mas_ways	*min;

	min = mas_ways;
	while (mas_ways)
	{
		if (mas_ways->iter < min->iter)
			min = mas_ways;
		mas_ways = mas_ways->next;
	}
	return (min);
}

static void		add_res_and_free_memory(t_lemin *lem)
{
	t_mas_ways	*min;

	get_iters(lem->mas_ways, lem);
	min = get_min_mas_ways(lem->mas_ways);
	del_mas_ways(&lem->mas_ways, min);
	add_to_mas_res(&lem->mas_res, min);
}

void		write_result(t_lemin *lem, int algo)
{
	int 		shift;

	shift = 0;
	while (++shift < TO)
	{
		algorithm2(lem, shift);
		add_res_and_free_memory(lem);
//		if (lem->mas_res->mas_ways->iter <= lem->target + 2)
//			break;
	}
}

t_mas_ways		*get_result(t_mas_res *res)
{
	t_mas_res	*min;

	min = res;
	while (res)
	{
		if (min->mas_ways->iter > res->mas_ways->iter)
			min = res;
		res = res->next;
	}
	return (min->mas_ways);
}

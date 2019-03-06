//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

int		step_for_end(t_lemin *lem)
{
	t_top_nodes	*min;
	t_lema		*lema;

	lema = create_lema_list(lem->top_end);
	while (lem->top_end)
	{
		count_pow_in_top_nodes(lem->top_end, END);
		min = get_min_pow_top_node(lem->top_end);
		connect_available(min, END);
		del_top_node(&lem->top_end, min);
	}
	lem->top_end = create_top_node_list(lema, END, lem);
	return (lem->top_start ? 1 : 0);
}

int		step_for_start(t_lemin *lem)
{
	t_top_nodes	*min;
	t_lema		*lema;

	lema = create_lema_list(lem->top_start);
	while (lem->top_start)
	{
		count_pow_in_top_nodes(lem->top_start, START);
		min = get_min_pow_top_node(lem->top_start);
		connect_available(min, START);
		del_top_node(&lem->top_start, min);
	}
	lem->top_start = create_top_node_list(lema, START, lem);
	return (lem->top_start ? 1 : 0);
}
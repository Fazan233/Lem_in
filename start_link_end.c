//
// Created by Vladyslav USLYSTYI on 2019-03-13.
//

#include "lem_in.h"

int 	start_link_end(t_lemin *lem)
{
	t_edge	*edge;

	edge = lem->graph;
	while (edge)
	{
		if ((edge->a == lem->start_vert && edge->b == lem->end_vert) ||
			(edge->b == lem->start_vert && edge->a == lem->end_vert))
			return (1);
		edge = edge->next;
	}
	return (0);
}
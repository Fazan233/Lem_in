//
// Created by Vladyslav USLYSTYI on 2019-02-22.
//

#include "lem_in.h"

t_verticle		*get_min_vert(t_verticle *v)
{
	t_verticle	*min;

	min = v;
	while (v)
	{
		if ((v->weight < min->weight && v->used == 0) || min->used == 1)
			min = v;
		v = v->next;
	}
	if (min->weight == INF || min->used == 1)
		return (NULL);
	min->used = 1;
	return (min);
}
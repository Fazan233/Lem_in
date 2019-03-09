//
// Created by Vladyslav USLYSTYI on 2019-03-09.
//

#include "lem_in.h"

int 	count_amount_rooms(t_lemin *lem)
{
	t_verticle	*v;
	int 		count;

	v = lem->vert;
	count = 0;
	while (v)
	{
		count++;
		v = v->next;
	}
	return (count);
}
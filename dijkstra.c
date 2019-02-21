//
// Created by Vladyslav USLYSTYI on 2019-02-21.
//

#include "lem_in.h"

void	set_begin_vals(t_verticle *v)
{
	t_verticle	*begin;

	begin = v;
	while (v != NULL)
	{
		v->weight = INF;
		v->short_way = NULL;
		v = v->next;
	}
	begin->weight = 0;
}

void		add_to_used(t_used_vert **used, t_verticle *v)
{
	if (*used == NULL)
	{
		*used = (t_used_vert*)malloc(sizeof(t_used_vert));
		(*used)->next = NULL;
		(*used)->vert = v;
	}
	else
	{
		while ((*used)->next != NULL)
			*used = (*used)->next;
		(*used)->next = (t_used_vert*)malloc(sizeof(t_used_vert));
		(*used)->next->next = NULL;
		(*used)->vert = v;
	}
}

void		del_list(t_used_vert **used)
{

}

t_verticle	*get_min_vert(t_verticle *v)
{
	static t_used_vert	*used;

	while (v != NULL)
	{
		if (v->weight != INF)
		{
			while (used != NULL)
			{
				if (used->vert != v)
				{
					add_to_used(&used, v);
					return (v);
				}
			}	
		}
		else if (v->weight != INF)
		{

		}
	}
	return (NULL);
}

t_way	*dijkstra(t_verticle *v, t_lemin *lem)
{
	t_verticle	*curr_vert;

	set_begin_vals(v);

}
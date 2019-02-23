//
// Created by Vladyslav USLYSTYI on 2019-02-23.
//

#include "lem_in.h"

void		turn_off_on_light_on_way(t_way *way, t_lemin *lem, int mode)
{
	if (way)
	{
		way = way->next;
		while (way->vert != lem->end_vert)
		{
			way->vert->light = mode == 0 ? 0 : 1;
			way = way->next;
		}
	}
}

void		turn_off_on_light_on_ways(t_ways *ways, t_lemin *lem, int mode)
{
	if (ways)
	{
		while (ways)
		{
			turn_off_on_light_on_way(ways->way, lem, mode);
			ways = ways->next;
		}
	}
}

void		show_hide_first_edge_ways(t_mas_ways *mas_ways, int mode)
{
	t_ways	*tmp;

	while (mas_ways)
	{
		tmp = mas_ways->ways;
		while (tmp->next)
			tmp = tmp->next;
		tmp->way->short_way->available = mode == 0 ? 0 : 1;
		mas_ways = mas_ways->next;
	}
}

void		show_hide_way(t_way *way, int mode)
{
	t_way	*end;

	if (way)
	{
		end = way->prev;
		while (way != end)
		{
			way->short_way->available = mode == 0 ? 0 : 1;
			way = way->next;
		}
	}
}

void		show_hide_ways(t_ways *ways, int mode)
{
	while (ways)
	{
		show_hide_way(ways->way, mode);
		ways = ways->next;
	}
}

t_ways		*find_list_ways(t_lemin *lem, t_mas_ways *mas_ways)
{
	t_ways	*ways;
	t_way	*way;

	ways = NULL;
	show_hide_first_edge_ways(mas_ways, 0);
	while ((way = dijkstra(lem)))
	{
		show_hide_way(way, 0);
		turn_off_on_light_on_way(way, lem, 0);
		add_new_way_to_ways(&ways, way);
		ways->len = lem->end_vert->weight;
	}
	show_hide_first_edge_ways(mas_ways, 1);
	if (ways)
	{
		while ((way = dijkstra(lem)))
		{
			show_hide_way(way, 0);
			add_new_way_to_ways(&ways, way);
			ways->len = lem->end_vert->weight;
		}
	}
	turn_off_on_light_on_ways(ways, lem, 1);
	show_hide_ways(ways, 1);
	return (ways);
}
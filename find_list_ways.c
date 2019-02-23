//
// Created by Vladyslav USLYSTYI on 2019-02-23.
//

#include "lem_in.h"

void		show_hide_first_edge_ways(t_mas_ways *mas_ways, int mode)
{
	while (mas_ways && mas_ways->ways && mas_ways->ways->way)
	{
		mas_ways->ways->way->short_way->available = mode == 0 ? 0 : 1;
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

t_ways		*find_list_ways(t_lemin *lem)
{
	t_ways	*ways;
	t_way	*way;

	ways = NULL;
	show_hide_first_edge_ways(lem->mas_ways, 0);
	while ((way = dijkstra(lem)))
	{
		show_hide_way(way, 0);
		add_new_way_to_ways(&ways, way);
		ways->len = lem->end_vert->weight;
	}
	show_hide_first_edge_ways(lem->mas_ways, 1);
	while ((way = dijkstra(lem)))
	{
		show_hide_way(way, 0);
		add_new_way_to_ways(&ways, way);
		ways->len = lem->end_vert->weight;
	}
	show_hide_ways(ways, 1);
	return (ways);
}
//
// Created by Vladyslav USLYSTYI on 2019-02-23.
//

#include "lem_in.h"
#include "bfs.h"

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

void		show_hide_first_edge_ways1(t_mas_ways *mas_ways, int mode)
{
	t_ways	*tmp;

	while (mas_ways)
	{
		tmp = mas_ways->ways;
		tmp->way->short_way->available = mode == 0 ? 0 : 1;
//		tmp->way->next->vert->available = mode == 0 ? 0 : 1;
		mas_ways = mas_ways->next;
	}
}

void		show_hide_way1(t_way *way, int mode, t_lemin *lem)
{
	t_way		*end;
	t_list_e	*list_e;

	if (way)
	{
		end = way->prev;
		way = way->next;
		while (way != end)
		{
			list_e = find_list_e(lem->list_v, way->vert);
			while (list_e)
			{
				list_e->e->available = (mode == 0 ? 0 : 1);
				list_e = list_e->next;
			}
//			way->vert->available = (mode == 0 ? 0 : 1);
			way = way->next;
		}
	}
}

void		show_hide_ways1(t_ways *ways, int mode, t_lemin *lem)
{
	while (ways)
	{
		show_hide_way1(ways->way, mode, lem);
		ways = ways->next;
	}
}

void		show_hide_first_edge_ways2(t_mas_ways *mas_ways, int mode)
{
	t_ways	*tmp;

	while (mas_ways)
	{
		tmp = mas_ways->ways;
		tmp->way->short_way->available = mode == 0 ? 0 : 1;
//		tmp->way->next->vert->available = mode == 0 ? 0 : 1;
		mas_ways = mas_ways->next;
	}
}

void		show_hide_way2(t_way *way, int mode, t_lemin *lem)
{
	t_way		*end;
	t_list_e	*list_e;

	if (way)
	{
		end = way->prev;
		way = way->next;
		while (way != end)
		{
			list_e = find_list_e(lem->list_v, way->vert);
			while (list_e)
			{
				list_e->e->available = (mode == 0 ? 0 : 1);
				list_e = list_e->next;
//				way->short_way->available = (mode == 0 ? 0 : 1);
			}
//			way->vert->available = (mode == 0 ? 0 : 1);
			way = way->next;
		}
	}
}

void		show_hide_ways2(t_ways *ways, int mode, t_lemin *lem)
{
	while (ways)
	{
		show_hide_way2(ways->way, mode, lem);
		ways = ways->next;
	}
}

//int 		identical_way(t_way *way1, t_way *way2)
//{
//	t_way	*end;
//
//	if (!way1 || !way2)
//		return (0);
//	end = way1->prev;
//	while (way1 != end && way2 != end)
//	{
//		if (way1->vert != way2->vert)
//			return (0);
//		way1 = way1->next;
//		way2 = way2->next;
//	}
//	if (way1->vert == way2->vert)
//		return (1);
//	return (0);
//}
//
//int 		is_ident_way_in_ways(t_way *way, t_ways *ways)
//{
//	while (ways)
//	{
//		if (identical_way(way, ways->way))
//			return (1);
//		ways = ways->next;
//	}
//	return (0);
//}
//
//int 		is_ident_way_in_mas_ways(t_way *way, t_mas_ways *mas_ways)
//{
//	while (mas_ways)
//	{
//		if (is_ident_way_in_ways(way, mas_ways->ways))
//			return (1);
//		mas_ways = mas_ways->next;
//	}
//	return (0);
//}

t_ways		*find_list_ways1(t_lemin *lem, t_mas_ways *mas_ways)
{
	t_ways	*ways;
	t_way	*way;

	ways = NULL;
	show_hide_first_edge_ways1(mas_ways, 0);
	while ((way = dijkstra(lem)))
	{
		show_hide_way1(way, 0, lem);
//		print_way(way);
//		turn_off_on_light_on_way(way, lem, 0);
		add_new_way_to_ways(&ways, way, lem);
	}
	show_hide_first_edge_ways1(mas_ways, 1);
	if (ways)
		while ((way = dijkstra(lem)))
		{
			show_hide_way1(way, 0, lem);
//			print_way(way);
//			turn_off_on_light_on_way(way, lem, 0);
			add_new_way_to_ways(&ways, way, lem);
		}
//	turn_off_on_light_on_ways(ways, lem, 1);
	show_hide_ways1(ways, 1, lem);
	return (ways);
}

t_ways		*find_list_ways2(t_lemin *lem, t_mas_ways *mas_ways)
{
	t_ways	*ways;
	t_way	*way;

	ways = NULL;
	show_hide_first_edge_ways2(mas_ways, 0);
	while ((way = bfs(lem)))
	{
		show_hide_way2(way, 0, lem);
//		print_way(way);
		add_new_way_to_ways(&ways, way, lem);
	}
	show_hide_first_edge_ways2(mas_ways, 1);
	if (ways)
		while ((way = bfs(lem)))
		{
			show_hide_way2(way, 0, lem);
//			print_way(way);
			add_new_way_to_ways(&ways, way, lem);
		}
//	turn_off_on_light_on_ways(ways, lem, 1);
	show_hide_ways2(ways, 1, lem);
	return (ways);
}
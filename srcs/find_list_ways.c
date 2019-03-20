/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_list_ways.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:56:58 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 12:58:29 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		show_hide_first_edge_ways(t_min_way *min_way, int mode)
{
	while (min_way)
	{
		min_way->way->short_way->available = mode == 0 ? 0 : 1;
		min_way = min_way->next;
	}
}

static void		show_hide_way(t_way *way, int mode, t_lemin *lem)
{
	t_way		*end;
	t_list_e	*list_e;

	if (way)
	{
		end = way->prev;
		way = way->next;
		if (way == end)
		{
			way = way->next;
			way->short_way->available = (mode == 0 ? 0 : 1);
			return ;
		}
		while (way != end)
		{
			list_e = lem->list_v[way->vert->n].list_e;
			while (way->vert->mult == 0 && list_e)
			{
				list_e->e->available = (mode == 0 ? 0 : 1);
				list_e = list_e->next;
			}
			way = way->next;
		}
	}
}

static void		show_hide_ways(t_ways *ways, int mode, t_lemin *lem)
{
	while (ways)
	{
		show_hide_way(ways->way, mode, lem);
		ways = ways->next;
	}
}

t_ways			*find_list_ways(t_lemin *lem, t_mas_ways *mas_ways)
{
	t_ways		*ways;
	t_way		*way;
	t_min_way	*min_way;

	min_way = get_min_way_list(mas_ways);
	ways = NULL;
	show_hide_first_edge_ways(min_way, 0);
	while ((way = bfs(lem)))
	{
		show_hide_way(way, 0, lem);
		add_new_way_to_ways(&ways, way, lem);
	}
	show_hide_first_edge_ways(min_way, 1);
	del_list_min_way(&min_way);
	if (ways)
		while ((way = bfs(lem)))
		{
			show_hide_way(way, 0, lem);
			add_new_way_to_ways(&ways, way, lem);
		}
	show_hide_ways(ways, 1, lem);
	return (ways);
}

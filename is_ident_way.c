//
// Created by Vladyslav USLYSTYI on 2019-03-09.
//

#include "lem_in.h"
#define ERR_MW "Couldn't allocate memory for list of min_ways.\n"

int 		identical_way(t_way *way1, t_way *way2)
{
	t_way	*end;

	if (!way1 || !way2)
		return (0);
	end = way1->prev;
	while (way1 != end && way2 != end)
	{
		if (way1->vert != way2->vert)
			return (0);
		way1 = way1->next;
		way2 = way2->next;
	}
	if (way1->vert == way2->vert)
		return (1);
	return (0);
}

void		add_min_way(t_min_way **min_way, t_way *way)
{
	t_min_way	*new_mw;

	new_mw = (t_min_way*)ft_memalloc(sizeof(t_min_way));
	if (!new_mw)
		ft_error(ERR_MW);
	new_mw->way = way;
	if (*min_way == NULL)
		*min_way = new_mw;
	else
	{
		new_mw->next = *min_way;
		*min_way = new_mw;
	}
}

void		del_list_min_way(t_min_way **min_way)
{
	t_min_way	*tmp;

	if (*min_way)
	{
		while ((*min_way)->next)
		{
			tmp = *min_way;
			*min_way = (*min_way)->next;
			free(tmp);
		}
		free(*min_way);
		*min_way = NULL;
	}
}

int 		ident_way_in_min_way_list(t_min_way *min_way, t_way *way)
{
	while (min_way)
	{
		if (identical_way(min_way->way, way))
			return (1);
		min_way = min_way->next;
	}
	return (0);
}

t_min_way	*get_min_way_list(t_mas_ways *mas_ways)
{
	t_min_way	*min_way;
	t_ways		*ways;

	min_way = NULL;
	while (mas_ways)
	{
		ways = mas_ways->ways;
		while (ways)
		{
			if (!ident_way_in_min_way_list(min_way, ways->way))
			{
				add_min_way(&min_way, ways->way);
				break ;
			}
			ways = ways->next;
		}
		mas_ways = mas_ways->next;
	}
	return (min_way);
}


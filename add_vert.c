//
// Created by Vladyslav USLYSTYI on 2019-02-20.
//

#include "lem_in.h"

t_verticle	*create_new_vert(char *name, char *x, char *y)
{
	t_verticle	*vert;

	vert = (t_verticle*)malloc(sizeof(t_verticle));
	if (vert)
	{
		vert->color = 0;
		vert->x = ft_atoi(x);
		vert->y = ft_atoi(y);
		vert->next = NULL;
		vert->prev = NULL;
		vert->short_way = NULL;
		vert->light = 1;
		vert->name = ft_strdup(name);
		return (vert);
	}
	ft_printf(ERROR_ALLOCATE);
	exit(1);
}

void	add_new_vert(t_verticle **vert, t_verticle *new_vert)
{
	if (*vert == NULL)
		*vert = new_vert;
	else
	{
		(*vert)->prev = new_vert;
		new_vert->next = (*vert);
		*vert = new_vert;
//		new_vert->next = *vert;
//		new_vert->prev = (*vert)->prev;
//		(*vert)->prev->next = new_vert;
//		if (new_vert->prev == (*vert))
//			(*vert)->next = new_vert;
//		(*vert)->prev = new_vert;
	}
}

t_edge	*create_edge(t_verticle *a, t_verticle *b)
{
	t_edge	*edge;

	edge = (t_edge*)malloc(sizeof(t_edge));
	if (edge)
	{
		edge->a = a;
		edge->b = b;
		edge->available = 1;
		edge->next = NULL;
		edge->prev = NULL;
		return (edge);
	}
	ft_printf(ERROR_ALLOCATE);
	exit(1);
}

void	add_new_edge(t_edge **graph, t_edge *edge)
{
	if (*graph == NULL)
		*graph = edge;
	else
	{
		edge->next = *graph;
		(*graph)->prev = edge;
		*graph = edge;
	}
}

t_way	*create_new_way(t_verticle *v)
{
	t_way	*way;

	way = (t_way*)malloc(sizeof(t_way));
	if (way)
	{
		way->vert = v;
		way->ant = 0;
		return (way);
	}
	ft_printf(ERROR_ALLOCATE);
	exit(1);
}

void	add_new_vert_to_way(t_way **way, t_verticle *vert)
{
	t_way	*new_way;

	new_way = create_new_way(vert);
	if (*way == NULL)
	{
		new_way->next = new_way;
		new_way->prev = new_way;
		*way = new_way;
	}
	else
	{
		new_way->next = *way;
		new_way->prev = (*way)->prev;
		if (new_way->prev == *way)
			(*way)->next = new_way;
		else
			(*way)->prev->next = new_way;
		(*way)->prev = new_way;
		*way = new_way;
	}
}

void	add_new_way_to_ways(t_ways **ways, t_way *way, t_lemin *lem)
{
	t_ways	*tmp;
	t_ways	*tmp_ways;

	tmp = (t_ways*)malloc(sizeof(t_ways));
	if (tmp)
	{
		tmp->way = way;
		tmp->next = NULL;
		tmp->len = lem->end_vert->weight;
		if (*ways == NULL)
			*ways = tmp;
		else
		{
			tmp_ways = *ways;
			while (tmp_ways->next != NULL)
				tmp_ways = tmp_ways->next;
			tmp_ways->next = tmp;
		}
	}
	else
	{
		ft_printf(ERROR_ALLOCATE);
		exit(1);
	}
}
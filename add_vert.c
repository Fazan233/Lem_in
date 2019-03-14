//
// Created by Vladyslav USLYSTYI on 2019-02-20.
//

#include "lem_in.h"
#define ERR_VER "Error!\nAllocation memory is no available for vertices!\n"
#define ERR_EDGE "Error!\nAllocation memory is no available for edges!\n"

t_verticle	*create_new_vert(char *name, int x, int y)
{
	t_verticle	*vert;

	vert = (t_verticle*)malloc(sizeof(t_verticle));
	if (vert)
	{
		vert->x = x;
		vert->y = y;
		vert->next = NULL;
		vert->prev = NULL;
		vert->short_way = NULL;
		vert->name = ft_strdup(name);
		return (vert);
	}
	ft_error(ERR_VER);
	return (0);
}

void	add_new_vert(t_verticle **vert, t_verticle *new_vert)
{
	if (*vert == NULL)
	{
		new_vert->n = 0;
		*vert = new_vert;
	}
	else
	{
		(*vert)->prev = new_vert;
		new_vert->next = (*vert);
		*vert = new_vert;
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
	ft_error(ERR_EDGE);
	return (0);
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
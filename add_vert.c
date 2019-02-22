//
// Created by Vladyslav USLYSTYI on 2019-02-20.
//

#include "lem_in.h"

t_verticle	*create_new_vert(int weight)
{
	t_verticle	*vert;

	vert = (t_verticle*)malloc(sizeof(t_verticle));
	if (vert)
	{
		vert->next = NULL;
		vert->prev = NULL;
		vert->weight = weight;
		return (vert);
	}
	ft_printf("Memory didn't allocate (");
	exit(1);
}

void	add_new_vert(t_verticle **vert, t_verticle *new_vert)
{
	if (*vert == NULL)
	{
		*vert = new_vert;
		(*vert)->next = *vert;
		(*vert)->prev = *vert;
	}
	else
	{
		new_vert->next = *vert;
		new_vert->prev = (*vert)->prev;
		(*vert)->prev->next = new_vert;
		if (new_vert->prev == (*vert))
			(*vert)->next = new_vert;
		(*vert)->prev = new_vert;
	}
}

t_way	*create_new_way(t_verticle *v)
{
	t_way	*way;

	way = (t_way*)malloc(sizeof(t_way));
	if (way)
	{
		way->next = NULL;
		way->prev = NULL;
		way->vert = v;
		return (way);
	}
	ft_printf("Memory couldn't allocate (");
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
	}
}
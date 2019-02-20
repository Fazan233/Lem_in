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
//	vert->name = ft_strdup(name);
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
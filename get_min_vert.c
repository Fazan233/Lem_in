//
// Created by Vladyslav USLYSTYI on 2019-02-22.
//

#include "lem_in.h"

static void		add_to_used(t_used_vert **used, t_verticle *v)
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
		(*used)->next->vert = v;
	}
}

void		add_to_used_edges(t_used_edge **used, t_edge *e)
{
	if (*used == NULL)
	{
		*used = (t_used_edge*)malloc(sizeof(t_used_edge));
		(*used)->next = NULL;
		(*used)->edge = e;
	}
	else
	{
		while ((*used)->next != NULL)
			*used = (*used)->next;
		(*used)->next = (t_used_edge*)malloc(sizeof(t_used_edge));
		(*used)->next->next = NULL;
		(*used)->next->edge = e;
	}
}

static int 		is_in_used_list(t_used_vert *used, t_verticle *v)
{
	while (used)
	{
		if (used->vert == v)
			return (1);
		used = used->next;
	}
	return (0);
}

static void		del_list(t_used_vert **used)
{
	t_used_vert			*tmp;

	while ((*used)->next)
	{
		tmp = *used;
		*used = (*used)->next;
		free(tmp);
	}
	free(*used);
	*used = NULL;
}

void		del_list_edges(t_used_edge **used)
{
	t_used_edge			*tmp;

	if (*used)
	{
		while ((*used)->next)
		{
			tmp = *used;
			*used = (*used)->next;
			free(tmp);
		}
		free(*used);
		*used = NULL;
	}
}

t_verticle		*get_min_vert(t_verticle *v, t_lemin *lem)
{
	t_used_vert			*used_tmp;

	if (!lem->used && v && v->weight != INF)
	{
		add_to_used(&lem->used, v);
		return (v);
	}
	while (v != NULL && v->weight != INF)
	{
		used_tmp = lem->used;
		while (used_tmp)
			if (!is_in_used_list(lem->used, v))
			{
				if (v->weight == lem->end_vert->weight)
					v = lem->end_vert;
				add_to_used(&used_tmp, v);
				if (v == lem->end_vert)
					del_list(&lem->used);
				return (v);
			}
			else
				used_tmp = used_tmp->next;
		v = v->next;
	}
	del_list(&lem->used);
	return (NULL);
}
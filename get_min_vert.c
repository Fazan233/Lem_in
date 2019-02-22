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
		(*used)->vert = v;
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

t_verticle		*get_min_vert(t_verticle *v)
{
	static t_used_vert	*used;
	t_used_vert			*used_tmp;

	if (!used && v && v->weight != INF)
	{
		add_to_used(&used, v);
		return (v);
	}
	while (v != NULL && v->weight != INF)
	{
		used_tmp = used;
		while (used_tmp)
			if (!is_in_used_list(used_tmp, v))
			{
				add_to_used(&used, v);
				return (v);
			}
			else
				used_tmp = used_tmp->next;
		v = v->next;
	}
	del_list(&used);
	return (NULL);
}
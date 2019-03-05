//
// Created by Vladyslav USLYSTYI on 2019-02-26.
//

#include "lem_in.h"

t_list_v	*create_list_v(t_verticle *v, t_list_e *list_e)
{
	t_list_v	*list_v;

	list_v = (t_list_v*)malloc(sizeof(t_list_v));
	list_v->list_e = list_e;
	list_v->v = v;
	return (list_v);
}

void		add_to_list_v(t_list_v **list_v, t_verticle *v, t_list_e *list_e)
{
	t_list_v	*tmp;

	tmp = create_list_v(v, list_e);
	if (*list_v == NULL)
		tmp->next = NULL;
	else
		tmp->next = *list_v;
	*list_v = tmp;
}

t_list_e	*create_list_e(t_edge *e)
{
	t_list_e	*list_e;

	list_e = (t_list_e*)malloc(sizeof(t_list_e));
	list_e->e = e;
	return (list_e);
}

void		add_to_list_e(t_list_e **list_e, t_edge *e)
{
	t_list_e	*tmp;

	tmp = create_list_e(e);
	if (*list_e == NULL)
		tmp->next = NULL;
	else
		tmp->next = *list_e;
	*list_e = tmp;
}

t_list_e	*get_list_e(t_lemin *lem, t_verticle *v)
{
	t_list_e	*list_e;
	t_edge		*edge;

	list_e = NULL;
	edge = lem->graph;
	while (edge)
	{
		if (v == edge->a || v == edge->b)
			add_to_list_e(&list_e, edge);
		edge = edge->next;
	}
	return (list_e);
}

int 		is_v_in_list_v(t_list_v *list_v, t_verticle *v)
{
	while (list_v)
	{
		if (list_v->v == v)
			return (1);
		list_v = list_v->next;
	}
	return (0);
}

t_list_v	*get_list_v(t_lemin *lem, t_verticle *v)
{
	t_list_v	*list_v;
	t_list_e	*list_e;

	list_v = NULL;
	while (v)
	{
		if (!is_v_in_list_v(list_v, v))
		{
			list_e = get_list_e(lem, v);
			if (list_e)
				add_to_list_v(&list_v, v, list_e);
		}
		v = v->next;
	}
	return (list_v);
}
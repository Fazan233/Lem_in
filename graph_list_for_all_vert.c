//
// Created by Vladyslav USLYSTYI on 2019-02-26.
//

#include "lem_in.h"

void		add_to_list_e(t_list_e **list_e, t_edge *e)
{
	t_list_e	*tmp;

	tmp = (t_list_e*)malloc(sizeof(t_list_e));
	tmp->e = e;
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

t_list_v	*get_list_v(t_lemin *lem, t_verticle *v)
{
	t_list_v	*list_v;
	t_list_e	*list_e;
	int 		i;

	i = 0;
	list_v = (t_list_v*)ft_memalloc(sizeof(t_list_v) * lem->amount);
	while (v)
	{
		list_e = get_list_e(lem, v);
		(list_v + i)->list_e = list_e;
		(list_v + i)->v = v;
		i++;
		v = v->next;
	}
	return (list_v);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_list_for_all_vert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:00:48 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:01:28 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ERR_LIST_V "Couldn't allocate memory for massive of vertices.\n"
#define ERR_LIST_E "Couldn't allocate memory for list of edges.\n"

static void		add_to_list_e(t_list_e **list_e, t_edge *e)
{
	t_list_e	*tmp;

	tmp = (t_list_e*)malloc(sizeof(t_list_e));
	if (!list_e)
		ft_error(ERR_LIST_E);
	tmp->e = e;
	if (*list_e == NULL)
		tmp->next = NULL;
	else
		tmp->next = *list_e;
	*list_e = tmp;
}

static t_list_e	*get_list_e(t_lemin *lem, t_verticle *v)
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

t_list_v		*get_list_v(t_lemin *lem, t_verticle *v)
{
	t_list_v	*list_v;
	t_list_e	*list_e;
	int			i;

	i = 0;
	list_v = (t_list_v*)ft_memalloc(sizeof(t_list_v) * lem->amount);
	if (!list_v)
		ft_error(ERR_LIST_V);
	while (v)
	{
		list_e = get_list_e(lem, v);
		(list_v + i)->list_e = list_e;
		i++;
		v = v->next;
	}
	return (list_v);
}

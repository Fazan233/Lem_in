/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_short_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:59:21 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 12:59:32 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define GET_OTHER_VERT(curr, edge) curr == edge->a ? edge->b : edge->a

t_way	*get_short_way(t_lemin *lem)
{
	t_way		*way;
	t_verticle	*v;

	way = NULL;
	v = lem->end_vert;
	if (v->short_way == NULL)
		return (NULL);
	while (1)
	{
		add_new_vert_to_way(&way, v);
		if (v == lem->end_vert)
			way->short_way = NULL;
		else
			way->short_way = way->next->vert->short_way;
		if (v->short_way == NULL)
			break ;
		else
			v = GET_OTHER_VERT(v, v->short_way);
	}
	return (way);
}

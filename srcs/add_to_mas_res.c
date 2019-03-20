/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_mas_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:48:35 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 12:48:49 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_to_mas_res(t_mas_res **mas_res, t_mas_ways *res)
{
	t_mas_res	*new_res;

	new_res = (t_mas_res*)ft_memalloc(sizeof(t_mas_res));
	new_res->mas_ways = res;
	if (*mas_res != NULL)
		new_res->next = *mas_res;
	*mas_res = new_res;
}

void		add_to_mas_ways(t_mas_ways **mas_ways, t_ways *ways)
{
	t_mas_ways	*tmp;
	t_mas_ways	*t;

	tmp = (t_mas_ways*)malloc(sizeof(t_mas_ways));
	if (tmp)
	{
		tmp->ways = ways;
		tmp->iter = 0;
		tmp->next = NULL;
		if (*mas_ways == NULL)
			*mas_ways = tmp;
		else
		{
			t = *mas_ways;
			while (t->next)
				t = t->next;
			t->next = tmp;
		}
	}
}

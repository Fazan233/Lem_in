/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_mas_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:56:07 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 12:56:30 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	del_way(t_way **way)
{
	t_way		*tmp;

	(*way)->prev->next = NULL;
	while ((*way)->next)
	{
		tmp = *way;
		*way = (*way)->next;
		free(tmp);
	}
	free(*way);
	*way = NULL;
}

static void	del_ways(t_ways **ways)
{
	t_ways		*tmp;

	while ((*ways)->next)
	{
		tmp = *ways;
		*ways = (*ways)->next;
		del_way(&tmp->way);
		free(tmp);
	}
	del_way(&(*ways)->way);
	free(*ways);
	*ways = NULL;
}

void		del_mas_ways(t_mas_ways **mas_ways, t_mas_ways *exept)
{
	t_mas_ways	*tmp;

	if (*mas_ways)
	{
		while ((*mas_ways)->next)
		{
			if (*mas_ways == exept)
			{
				*mas_ways = (*mas_ways)->next;
				continue;
			}
			tmp = *mas_ways;
			*mas_ways = (*mas_ways)->next;
			del_ways(&tmp->ways);
			free(tmp);
		}
		if (*mas_ways != exept)
		{
			del_ways(&(*mas_ways)->ways);
			free(*mas_ways);
		}
		*mas_ways = NULL;
	}
}

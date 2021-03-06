/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:23:49 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:24:32 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ERR_WAY "Couldn't allocate memory for list of way.\n"
#define ERR_WAYS "Couldn't allocate memory for list of ways.\n"

static t_way	*create_new_way(t_verticle *v)
{
	t_way	*way;

	way = (t_way*)malloc(sizeof(t_way));
	if (way)
	{
		way->vert = v;
		way->ant = 0;
		return (way);
	}
	ft_error(ERR_WAY);
	return (0);
}

void			add_new_vert_to_way(t_way **way, t_verticle *vert)
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
		*way = new_way;
	}
}

void			add_new_way_to_ways(t_ways **ways, t_way *way, t_lemin *lem)
{
	t_ways	*tmp;
	t_ways	*tmp_ways;

	tmp = (t_ways*)malloc(sizeof(t_ways));
	if (!tmp)
		ft_error(ERR_WAYS);
	if (tmp)
	{
		tmp->way = way;
		tmp->next = NULL;
		tmp->len = lem->end_vert->weight;
		if (*ways == NULL)
			*ways = tmp;
		else
		{
			tmp_ways = *ways;
			while (tmp_ways->next != NULL)
				tmp_ways = tmp_ways->next;
			tmp_ways->next = tmp;
		}
	}
}

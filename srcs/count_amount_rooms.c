/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_amount_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:53:41 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 12:54:18 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_amount_rooms(t_lemin *lem)
{
	t_verticle	*v;
	int			count;

	v = lem->vert;
	count = 0;
	while (v)
	{
		v->n = count;
		count++;
		v = v->next;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:26:28 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:26:32 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		change_start(t_ways **start, int shift)
{
	t_ways	*end;

	end = *start;
	while (end->next)
		end = end->next;
	end->next = *start;
	while (shift-- > 0)
		*start = (*start)->next;
	end = *start;
	while (end->next != *start)
		end = end->next;
	end->next = NULL;
}

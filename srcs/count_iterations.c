/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_iterations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:54:47 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 12:55:40 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		number_can_way(t_ways *ways, t_ways *begin)
{
	int		min;
	int		sum;

	sum = 0;
	while (begin != ways)
	{
		min = begin->len;
		sum = sum + (ways->len - min);
		begin = begin->next;
	}
	return (sum);
}

int		get_iter(t_ways *ways, int ants)
{
	int		counter;
	t_ways	*begin;
	int		tmp;

	begin = ways;
	counter = 0;
	while (ants > 0)
	{
		ways = begin;
		while (ways)
		{
			tmp = number_can_way(ways, begin);
			if (ants >= tmp)
				ants--;
			else
				break ;
			ways = ways->next;
		}
		counter++;
	}
	return (counter + begin->len - 1);
}

void	get_iters(t_mas_ways *mas_ways, t_lemin *lem)
{
	while (mas_ways)
	{
		bubble_sort_list_l_u(&mas_ways->ways);
		mas_ways->iter = get_iter(mas_ways->ways, lem->ants);
		mas_ways = mas_ways->next;
	}
}

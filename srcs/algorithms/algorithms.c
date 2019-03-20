/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:26:01 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:26:05 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lem_algos.h"

void		algorithm(t_lemin *lem, int shift)
{
	t_ways		*ways;

	while ((ways = find_list_ways(lem, lem->mas_ways)))
	{
		change_start(&ways, shift);
		add_to_mas_ways(&lem->mas_ways, ways);
	}
}

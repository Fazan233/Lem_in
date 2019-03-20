/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:47:37 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:47:41 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_map(char *str, t_lemin *lem)
{
	ft_strcpy(lem->pars.map + lem->pars.iter, str);
	lem->pars.iter = lem->pars.iter + (int)ft_strlen(str);
	lem->pars.map[lem->pars.iter] = '\n';
	lem->pars.iter++;
}

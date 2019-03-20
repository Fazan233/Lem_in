/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wish_list_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:24:56 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:25:06 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_wish_list(t_wish_list **wish, int ant)
{
	t_wish_list	*new_wish;
	t_wish_list	*tmp;

	new_wish = (t_wish_list*)ft_memalloc(sizeof(t_wish_list));
	new_wish->ant = ant;
	if (*wish == NULL)
		*wish = new_wish;
	else
	{
		tmp = *wish;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_wish;
	}
}

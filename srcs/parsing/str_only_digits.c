/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_only_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:59:20 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:59:22 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		str_only_digits(char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

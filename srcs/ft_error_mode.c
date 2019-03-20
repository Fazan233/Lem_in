/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:58:49 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 12:58:53 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_mode(char *std_mess, char *mode_mess, int mode)
{
	if (mode == 0)
		ft_printf("%s\n", std_mess);
	else
		ft_printf("%s\n", mode_mess);
	exit(1);
}

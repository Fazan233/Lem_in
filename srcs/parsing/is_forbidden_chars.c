/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_forbidden_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:49:48 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:50:10 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_forbidden_chars(char *str)
{
	if (*str == '#' || *str == 'L')
		return (1);
	return (0);
}

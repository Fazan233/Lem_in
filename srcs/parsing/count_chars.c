/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:48:07 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:48:08 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_delims(char *str, char c)
{
	int	i;
	int	count_chars;

	i = 0;
	count_chars = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			count_chars++;
			i++;
			while (*str == c)
			{
				str++;
				if (*str == c)
					count_chars++;
			}
		}
		if (*str != '\0')
			str++;
	}
	if (count_chars == i)
		return (i);
	else
		return (0);
}

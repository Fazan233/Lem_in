/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sharp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:00:44 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 21:01:51 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ERR_PROBL_ST_END "WOW you have some problem with start or end. FIX IT!"
#define ERR_AFT_BLOCK "A valid room must follows after operation ##block!"
#define ERR_AFT_MULT "A valid room must follows after operation ##multi_room!"

void		check_start_end(char **line, t_lemin *lem, int fd)
{
	int		flag;

	flag = (*line)[2] == 's' ? 0 : 1;
	free(*line);
	if (get_next_line(fd, line))
		if (is_valid_room(lem, line))
			if ((flag == 0 && !lem->start_vert) ||
				(flag == 1 && !lem->end_vert))
			{
				flag == 0 ? lem->start_vert = lem->vert : 0;
				flag == 1 ? lem->end_vert = lem->vert : 0;
				return ;
			}
	ft_error_mode(ERROR, ERR_PROBL_ST_END, lem->flag.debug);
}

void		check_block(t_lemin *lem, char **line, int fd)
{
	free(*line);
	if (get_next_line(fd, line))
		if (is_valid_room(lem, line))
		{
			lem->vert->block = 1;
			return ;
		}
	ft_error_mode(ERROR, ERR_AFT_BLOCK, lem->flag.debug);
}

void		check_multi_room(t_lemin *lem, char **line, int fd)
{
	free(*line);
	if (get_next_line(fd, line))
		if (is_valid_room(lem, line))
		{
			lem->vert->mult = 1;
			return ;
		}
	ft_error_mode(ERROR, ERR_AFT_MULT, lem->flag.debug);
}

void		check_sharp(t_lemin *lem, char **line, int fd)
{
	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
		check_start_end(line, lem, fd);
	else if (!ft_strcmp(*line, "##block"))
		check_block(lem, line, fd);
	else if (!ft_strcmp(*line, "##multi_room"))
		check_multi_room(lem, line, fd);
	else
	{
		if (!lem->target &&
			ft_strstr(*line, "#Here is the number of lines required:"))
			lem->target = get_target(*line);
		free(*line);
	}
}

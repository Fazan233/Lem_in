/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:52:25 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 13:57:35 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ERR_ST_END "The start and end rooms must be specified!"
#define ERR_ANT_NUM "Number of ants must be digit: 0 < ANT_NUM <= INT_MAX"
#define ERR_PROBL_ST_END "WOW you have some problem with start or end. FIX IT!"
#define EMTY_LINE " And maybe you have empty line, if it is true - delete it!"
#define PROBL_ST_END_EMPT_LINE ERR_PROBL_ST_END EMTY_LINE

static void		valid_num_of_ants(t_lemin *lem, int fd, char **line)
{
	char	*num;

	while (get_next_line(fd, line))
		if (**line == '#')
		{
			add_to_map(*line, lem);
			check_sharp(lem, line, fd);
		}
		else
			break ;
	if (str_only_digits(*line))
	{
		lem->ants = ft_atoi(*line);
		num = ft_itoa(lem->ants);
		if (ft_strcmp(*line, num))
		{
			free(num);
			ft_error_mode(ERROR, ERR_ANT_NUM, lem->flag.debug);
		}
		free(num);
	}
	add_to_map(*line, lem);
	free(*line);
	if (lem->ants <= 0)
		ft_error_mode(ERROR, ERR_ANT_NUM, lem->flag.debug);
}

static void		valid_rooms(t_lemin *lem, int fd, char **line)
{
	while (get_next_line(fd, line) > 0)
	{
		if (**line == '#')
		{
			add_to_map(*line, lem);
			check_sharp(lem, line, fd);
		}
		else if (!is_valid_room(lem, line))
			break ;
	}
}

static void		valid_links(t_lemin *lem, int fd, char **line)
{
	is_valid_link(lem, line);
	while (get_next_line(fd, line) > 0)
	{
		if (**line == '#')
		{
			add_to_map(*line, lem);
			check_sharp(lem, line, fd);
		}
		else
			is_valid_link(lem, line);
	}
    free(*line);
}

void			parsing(int fd, t_lemin *lem)
{
	char	*line;

	valid_num_of_ants(lem, fd, &line);
	valid_rooms(lem, fd, &line);
	if (lem->start_vert == NULL || lem->end_vert == NULL)
	{
		free(line);
		ft_error_mode(ERROR, PROBL_ST_END_EMPT_LINE, lem->flag.debug);
	}
	valid_links(lem, fd, &line);
}

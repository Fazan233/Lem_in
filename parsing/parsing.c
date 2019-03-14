//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#include "lem_in.h"
#define ERR_ST_END "The start and end rooms must be specified!"
#define ERR_ANT_NUM "Number of ants must be digit: 0 < ANT_NUM <= INT_MAX"
#define ERR_PROBL_ST_END "WOW you have some problem with start or end. FIX IT!"

void		check_sharp(t_lemin *lem, char **line, int fd)
{
	int 	flag;

	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
	{
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
	else
	{
		if (!lem->target &&
			ft_strstr(*line, "#Here is the number of lines required:"))
			lem->target = get_target(*line);
		free(*line);
	}
}

void		valid_num_of_ants(t_lemin *lem, int fd, char **line)
{
	char 	*num;

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


void 		valid_rooms(t_lemin *lem, int fd, char **line)
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

void 		valid_links(t_lemin *lem, int fd, char **line)
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
}


void		parsing(int fd, t_lemin *lem)
{
	char	*line;

	valid_num_of_ants(lem, fd, &line);
	valid_rooms(lem, fd, &line);
	if (lem->start_vert == NULL || lem->end_vert == NULL)
	{
		free(line);
		ft_error_mode(ERROR, ERR_ST_END, lem->flag.debug);
	}
	valid_links(lem, fd, &line);
}
//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#include "lem_in.h"
#include "parsing.h"

void		valid_num_of_ants(t_lemin *lem, int fd, char **line)
{
	get_next_line(fd, line);
	if (str_only_digits(*line))
		lem->ants = ft_atoi(*line);
	if (lem->ants != 0)
		add_to_map(*line, lem);
	free(*line);
	if (lem->ants == 0)
		ft_error(ERROR);
}

void		check_sharp(t_lemin *lem, char **line, int fd)
{
	int 	flag;

	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
	{
		flag = (*line)[2] == 's' ? 0 : 1;
		free(*line);
		if (get_next_line(fd, line))
			if (is_valid_room(lem, line))
			{
				flag == 0 ? lem->start_vert = lem->vert : 0;
				flag == 1 ? lem->end_vert = lem->vert : 0;
				return ;
			}
		ft_error(ERROR);
	}
	else
	{
		if (ft_strstr(*line, "#Here is the number of lines required:"))
			lem->target = get_target(*line);
	}
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
		if (!is_valid_room(lem, line))
			break ;
	}
}

void	parsing(int fd, t_lemin *lem)
{
	char	*line;

	valid_num_of_ants(lem, fd, &line);
	valid_rooms(lem, fd, &line);
	
}
//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#include "lem_in.h"
#include "parsing.h"

int		valid_num_of_ants(t_lemin *lem, int fd, char **line)
{
	if (get_next_line(fd, line) > 0)
	{
		if (str_only_digits(*line))
			lem->ants = ft_atoi(*line);
		if (lem->ants != 0)
		{
			add_to_map(*line, lem);
			free(*line);
			return (1);
		}
	}
	return (0);
}

int 	valid_rooms(t_lemin *lem, int fd, char **line)
{
	char	**room;

	while (get_next_line(fd, line) > 0)
	{
		if (count_delims(*line, ' ') == 2)
		{
			room = ft_strsplit(*line, ' ');
		}
		else
		{
			free(*line);
			break ;
		}
		free(*line);
	}
}

void	parsing(int fd, t_lemin *lem)
{
	char	*line;


}
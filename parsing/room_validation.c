//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#include "lem_in.h"
#define FORB_NAME "You have a room which has a forbidden name!"
#define COORD "Coordinates should be possitive and composed of numbers only!"
#define IDENT_ROOMS "There can be no two identical name of rooms!"
#define IDENT_COORD "You have two rooms with identical coordinates!"

static int 	is_in_vert_list(t_lemin *lem, char *name, int x, int y)
{
	t_verticle	*v;

	v = lem->vert;
	while (v)
	{
		if (!ft_strcmp(v->name, name))
			ft_error_mode(ERROR, IDENT_ROOMS, lem->flag.debug);
		if (v->x == x && v->y == y)
			ft_error_mode(ERROR, IDENT_COORD, lem->flag.debug);
		v = v->next;
	}
	return (0);
}

static void	del_2d_charmas(char ***mas)
{
	int			i;

	i = 0;
	while ((*mas)[i])
		free((*mas)[i++]);
	free(*mas);
}

void	room_validation(t_lemin *lem, char ***mas)
{
	int 	x;
	int		y;

	if (!is_forbidden_chars((*mas)[0]))
	{
		if (str_only_digits((*mas)[1]) && str_only_digits((*mas)[2]))
		{
			x = ft_atoi((*mas)[1]);
			y = ft_atoi((*mas)[2]);
			if (!is_in_vert_list(lem, (*mas)[0], x, y))
				add_new_vert(&lem->vert, create_new_vert((*mas)[0], x, y));
			del_2d_charmas(mas);
			return ;
		}
		else
			ft_error_mode(ERROR, COORD, lem->flag.debug);
	}
	del_2d_charmas(mas);
	ft_error_mode(ERROR, FORB_NAME, lem->flag.debug);
}

int		is_valid_room(t_lemin *lem, char **line)
{
	char	**room;

	if (count_delims(*line, ' ') == 2)
	{
		room = ft_strsplit(*line, ' ');
		add_to_map(*line, lem);
		free(*line);
		room_validation(lem, &room);
		return (1);
	}
	else
		return (0);
}
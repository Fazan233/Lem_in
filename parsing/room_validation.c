//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#include "lem_in.h"

int 	is_in_vert_list(t_lemin *lem, char *name, int x, int y)
{
	t_verticle	*v;

	v = lem->vert;
	while (v)
	{
		if (!ft_strcmp(v->name, name))
			return (1);
		if (v->x == x && v->y == y)
			return (1);
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
	char	*name;
	int 	x;
	int		y;
	int 	error;

	name = (*mas)[0];
	if (!is_forbidden_chars(name))
	{
		if (str_only_digits((*mas)[1]) && str_only_digits((*mas)[2]))
		{
			x = ft_atoi((*mas)[1]);
			y = ft_atoi((*mas)[2]);
			if (!(error = is_in_vert_list(lem, name, x, y)))
				add_new_vert(&lem->vert, create_new_vert(name, x, y));
			if (error == 0)
			{
				del_2d_charmas(mas);
				return;
			}
		}
	}
	del_2d_charmas(mas);
	ft_error(ERROR);
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
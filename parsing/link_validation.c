//
// Created by Vladyslav USLYSTYI on 2019-03-12.
//

#include "parsing.h"

int 	is_verts_in_list(t_lemin *lem, char *room1, char *room2,
							t_verticle *mas[])
{
	t_verticle	*v;
	int 		i;

	v = lem->vert;
	i = 0;
	while (v)
	{
		if (!ft_strcmp(v->name, room1))
		{
			mas[i] = v;
			i++;
		}
		else if (!ft_strcmp(v->name, room2))
		{
			mas[i] = v;
			i++;
		}
		v = v->next;
	}
	return (i == 2);
}

static void	del_2d_charmas(char ***mas)
{
	int			i;

	i = 0;
	while ((*mas)[i])
		free((*mas)[i++]);
	free(*mas);
}

int		is_link_in_graph(t_lemin *lem, char *room1, char *room2)
{
	t_edge		*edge;

	edge = lem->graph;
	while (edge)
	{
		if ((!ft_strcmp(room1, edge->a->name) &&
			!ft_strcmp(room2, edge->b->name)) ||
			(!ft_strcmp(room2, edge->a->name) &&
			!ft_strcmp(room1, edge->b->name)))
			return (1);
		edge = edge->next;
	}
	return (0);
}

void	link_validation(t_lemin *lem, char ***mas)
{
	t_verticle	*verts[2];
	int 		error;

	if (is_verts_in_list(lem, (*mas)[0], (*mas)[1], verts))
	{
		if (!(error = is_link_in_graph(lem, (*mas)[0], (*mas)[1])))
			add_new_edge(&lem->graph, create_edge(verts[0], verts[1]));
		if (error == 0)
		{
			del_2d_charmas(mas);
			return ;
		}
	}
	del_2d_charmas(mas);
	ft_error(ERROR);
}

void 	is_valid_link(t_lemin *lem, char **line)
{
	char	**link;

	if (count_delims(*line, '-') == 1)
	{
		link = ft_strsplit(*line, '-');
		if (link[0] && link[1])
		{
			add_to_map(*line, lem);
			free(*line);
			link_validation(lem, &link);
		}
		else
		{
			free(*line);
			ft_error(ERROR);
		}
	}
	else
	{
		free(*line);
		ft_error(ERROR);
	}
}
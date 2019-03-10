#include "lem_in.h"

t_verticle	*find_vert(t_verticle *v, char *name)
{
	while (v)
	{
		if (!ft_strcmp(v->name, name))
			return (v);
		v = v->next;
	}
	return (NULL);
}

void	del_2d_charmas(char **mas)
{
	int			i;

	i = 0;
	while (mas[i])
		free(mas[i++]);
	free(mas);
}

void	for_add_vert(t_lemin *lem, char **line, int fd, char **mas)
{
	t_verticle	*v;
	char 		**tmp;

	if ((*line)[0] == '#')
	{
		if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
		{
			free(*line);
			get_next_line(fd, line);
			tmp = ft_strsplit(*line, ' ');
			v = create_new_vert(tmp[0], tmp[1], tmp[2]);
			add_new_vert(&lem->vert, v);
			if (mas[0][2] == 's')
				lem->start_vert = v;
			else
				lem->end_vert = v;
			del_2d_charmas(tmp);
		}
		if (ft_strstr(*line, "#Here is the number of lines required:"))
		{
			char	*t;
			t = *line;
			while (!ft_isdigit(*t))
				t++;
			lem->target = ft_atoi(t);
		}

	}
	else
	{
		v = create_new_vert(mas[0], mas[1], mas[2]);
		add_new_vert(&lem->vert, v);
	}
}

void	for_add_edge(t_lemin *lem, char *str)
{
	char	**mas;
	t_edge	*edge;

	mas = ft_strsplit(str, '-');
	edge = create_edge(find_vert(lem->vert, mas[0]),
						find_vert(lem->vert, mas[1]));
	add_new_edge(&lem->graph, edge);
	free(mas);
}

void	parsing(int fd, t_lemin *lem)
{
	char		*line;
	char 		**mas;

	get_next_line(fd, &line);
	lem->ants = ft_atoi(line);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		mas = ft_strsplit(line, ' ');
		if (line[0] != '#' && mas[1] == NULL)
			for_add_edge(lem, mas[0]);
		else
			for_add_vert(lem, &line, fd, mas);
		free(line);
		del_2d_charmas(mas);
	}
//	while (del_single(&lem->graph, &lem->vert))
//		;
}
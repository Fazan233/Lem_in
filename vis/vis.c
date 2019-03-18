//
// Created by Vladyslav USLYSTYI on 2019-03-18.
//

#include <get_next_line.h>
#include <libft.h>
#include <lem_in.h>
#include <fcntl.h>

void	vis_pars()
{
	char	*line;
	int 	fd;

	fd = open("iters", O_CREAT | O_RDWR | O_TRUNC);
	while (get_next_line(0, &line) > 0)
	{
		if (*line == 'L')
			ft_fprintf(fd, "%s\n", line);
		if (!ft_strcmp(line, "-------------------------------"))
			break ;
		free(line);
	}
	if (!ft_strcmp(line, "-------------------------------"))
	{
		free(line);
	}
}

int		main(void)
{
	t_lemin	*lem;

	lem = ft_memalloc(sizeof(t_lemin));

}
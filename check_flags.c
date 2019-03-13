//
// Created by Vladyslav USLYSTYI on 2019-03-13.
//

#include "flags.h"
#include "lem_in.h"

void		init_flags(char c, t_flags *f)
{
	c == 'd' ? f->debug = 1 : 0;
	c == 'w' ? f->ways = 1 : 0;
	c == 'a' ? f->debug = 1 : 0;
}

void		show_usage(void)
{
	ft_printf("usage: ./generator [option]\n");
	exit (1);
}

void		read_flags(char *flags, t_flags *f)
{
	while (flags)
	{
		if (ft_strchr(FLAG_LIST, *flags))
			init_flags(*flags, f);
		else
			show_usage();
		flags++;
	}
}

void		check_flags(int ac, char **av, t_lemin *lem)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			read_flags(av[i] + 1, &lem->flag);
		else
			show_usage();
		i++;
	}
}
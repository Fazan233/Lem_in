//
// Created by Vladyslav USLYSTYI on 2019-03-13.
//

#include "lem_in.h"

static void		init_flags(char c, t_flags *f)
{
	c == 'e' ? f->debug = 1 : 0;
	c == 'w' ? f->ways = 1 : 0;
	c == 'a' ? f->all = 1 : 0;
	c == 'm' ? f->map = 1 : 0;
	c == 'g' ? f->go = 1 : 0;
	c == 'i' ? f->iter = 1 : 0;
	c == 't' ? f->target = 1 : 0;
	c == 'L' ? f->lem = 1 : 0;
}

static void		show_usage(void)
{
	ft_printf("usage: ./lem-in [{BOLD}-ewamgitL{EOC}]\n");
	ft_printf("If you want to see what means that flags ");
	ft_printf("enter {BOLD}--help{EOC}\n");
	exit (1);
}

static void		ckeck_ant(char **flags, t_lemin *lem)
{
	add_wish_list(&lem->wish_list, ft_atoi(*flags));
	while (ft_isdigit(**flags))
		(*flags)++;
}

static void		read_flags(char *flags, t_flags *f, t_lemin *lem)
{
	char	prev;

	while (*flags != '\0')
	{
		prev = *flags;
		if (ft_strchr(FLAG_LIST, *flags))
		{
			init_flags(*flags, f);
			flags++;
			if (prev == 'L' && ft_isdigit(*flags))
				ckeck_ant(&flags, lem);
		}
		else
			show_usage();
	}
}

void		check_flags(int ac, char **av, t_lemin *lem)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')

			read_flags(av[i] + 1, &lem->flag, lem);
		else
			show_usage();
		i++;
	}
}
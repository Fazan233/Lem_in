#include <fcntl.h>
#include "lem_in.h"
#define ERR_LEM "Couldn't allocate memory for variable lem.\n"

static void	init_lem(int fd, t_lemin *lem)
{
	lem->pars.map = (char*)ft_memalloc(200000);
	parsing(fd, lem);
	lem->amount = count_amount_rooms(lem);
	lem->list_v = get_list_v(lem, lem->vert);
	lem->list_ants = (t_ant*)ft_memalloc(sizeof(t_ant) * lem->ants);
}

static void	set_standart_flags(t_lemin *lem)
{
	lem->flag.map = 1;
	lem->flag.go = 1;
}

int main(int ac, char **av)
{
	t_lemin 	*lem;

	if (!(lem = (t_lemin*)malloc(sizeof(t_lemin))))
		ft_error(ERR_LEM);
	ft_bzero(lem, sizeof(t_lemin));
	if (ac == 2)
		help(av[1]);
	if (ac > 1)
		check_flags(ac, av, lem);
	else
		set_standart_flags(lem);
	init_lem(0, lem);
	write_result(lem);
	lem->result = get_result(lem->mas_res);
	print_data(lem);
	return (0);
}
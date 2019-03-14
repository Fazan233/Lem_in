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

int main(int ac, char **av)
{
	t_lemin 	*lem;
	int 		fd;

//	system("./generator.uu --big-superposition > test");
	fd = open("test", O_RDONLY);
	if (!(lem = (t_lemin*)malloc(sizeof(t_lemin))))
		ft_error(ERR_LEM);
	ft_bzero(lem, sizeof(t_lemin));
	if (ac > 1)
		check_flags(ac, av, lem);
	init_lem(fd, lem);
	write_result(lem);
	lem->result = get_result(lem->mas_res);
	print_data(lem);
	return (0);

}
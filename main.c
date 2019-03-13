#include <fcntl.h>
#include "lem_in.h"

static void	init_lem(int fd, t_lemin *lem)
{
	ft_bzero(lem, sizeof(t_lemin));
	lem->pars.map = (char*)ft_memalloc(200000);
	parsing(fd, lem);
	if (start_link_end(lem))
	{
		ft_printf("%s\n", lem->pars.map);
		ants_go_one_way(lem);
	}
	lem->amount = count_amount_rooms(lem);
	lem->list_v = get_list_v(lem, lem->vert);
}

int main()
{
	t_lemin 	*lem;
	int 		fd;
	t_mas_ways	*result;
//	if (ac)
//		;
//	fd = open(av[1], O_TRUNC | O_RDONLY);
	fd = open("test_3", O_RDONLY);
	lem = (t_lemin*)malloc(sizeof(t_lemin));
	init_lem(fd, lem);
	write_result(lem);
	result = get_result(lem->mas_res);
	ft_printf("%s\n", lem->pars.map);
	ants_go(result->ways, lem);
	ft_printf("{YELLOW}iters - %d{EOC}   {RED}target - %d{EOC}\n",
			result->iter, lem->target);
	system("leaks -q Lem_in");
	return (0);
}
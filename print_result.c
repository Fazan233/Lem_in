//
// Created by Vladyslav USLYSTYI on 2019-03-14.
//

#include "lem_in.h"

void		print_data(t_lemin *lem)
{
	int 	ant;

	ant = lem->ants;
	if (lem->flag.map)
		ft_printf("%s\n", lem->pars.map);
	if (lem->flag.go)
		ants_go(lem->result->ways, lem, lem->ants);
	lem->ants = ant;
	if (lem->flag.all)
		print_list_ants(lem);
	else if (lem->flag.lem)
		print_choosed_ant(lem);
	if (lem->flag.ways)
		print_ways(lem->result->ways);
	if (lem->flag.iter)
		ft_printf("{GREEN}Count of iterations:{EOC} {RED}%i{EOC}\n",
				lem->mas_res->mas_ways->iter);
	if (lem->flag.target)
	{
		ft_printf("{GREEN}Required iterations:{EOC} {RED}");
		if (lem->target)
			ft_printf("%i{EOC}\n", lem->target);
		else
			ft_printf("No specific number of iterations is required{EOC}\n");
	}
}
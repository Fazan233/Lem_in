//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#include "lem_in.h"

void	add_to_map(char *str, t_lemin *lem)
{
	ft_strcpy(lem->pars.map + lem->pars.iter, str);
	lem->pars.iter = lem->pars.iter + (int)ft_strlen(str);
	lem->pars.map[lem->pars.iter] = '\n';
	lem->pars.iter++;
}
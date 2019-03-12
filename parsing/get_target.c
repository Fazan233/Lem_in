//
// Created by User on 12.03.2019.
//

#include "lem_in.h"

int 	get_target(char *str)
{
	while (!ft_isdigit(*str))
		str++;
	return (ft_atoi(str));
}
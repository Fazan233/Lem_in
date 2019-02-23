//
// Created by User on 19.02.2019.
//

#include "lem_in.h"

void	print_list(t_verticle *start, t_verticle *end)
{
	int	i;

	while (start != end)
	{
		ft_printf("%d ", start->weight);
		start = start->next;
	}
	ft_printf("%d\n", end->weight);
}
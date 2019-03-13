//
// Created by User on 12.03.2019.
//

#include "libft.h"

void	ft_error(char *message)
{
	if (message)
		ft_printf("%s\n", message);
	system("leaks -q Lem_in");
	exit(1);
}
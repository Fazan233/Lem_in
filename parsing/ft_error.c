//
// Created by User on 12.03.2019.
//

#include "libft.h"

void	ft_error(char *message)
{
	if (message)
		ft_printf("%s\n", message);
	exit(1);
}
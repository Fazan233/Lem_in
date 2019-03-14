//
// Created by Vladyslav USLYSTYI on 2019-03-14.
//

#include "libft.h"

void	ft_error_mode(char *std_mess, char *mode_mess, int mode)
{
	if (mode == 0)
		ft_printf("%s\n", std_mess);
	else
		ft_printf("%s\n", mode_mess);
	exit(1);
}
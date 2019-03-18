//
// Created by Vladyslav USLYSTYI on 2019-03-18.
//

#include "libft.h"

void	help(char *help)
{
	if (!ft_strcmp(help, "--help"))
	{
		ft_printf("Flags for lem-in:\n");
		ft_printf("%8%\b-m  Show map of terrarium.\n");
		ft_printf("%8%\b-g  Show all iterations of ants moving.\n");
		ft_printf("%8%\b-w  Show the best parallel ways for our ants.\n");
		ft_printf("%8%\b-i  Show count of iterations of ants moving.\n");
		ft_printf("%8%\b-t  Show count of iterations ");
		ft_printf("which want our generator.\n");
		ft_printf("%8%\b-e  Error management. (Display the message which ");
		ft_printf("help to understand where was you take a mistake)\n");
		ft_printf("%8%\b-a  Show all ants and ways which they follow.\n");
		ft_printf("%3%\b-L[num]  Show a way which the ant ");
		ft_printf("with number [num] follows.\n");
		exit(0);
	}
}
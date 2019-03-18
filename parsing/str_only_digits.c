//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#include "lem_in.h"

int		str_only_digits(char *str)
{
	if (str && *str)
	{
		while (*str != '\0')
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}
//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

int		count_delims(char *str, char c)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			i++;
			while (*str == c)
				str++;
		}
		if (*str != '\0')
			str++;
	}
	return (i);
}
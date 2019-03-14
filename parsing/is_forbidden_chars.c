//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

int 	is_forbidden_chars(char *str)
{

	if (*str == '#' || *str == 'L')
		return (1);
	return (0);
}
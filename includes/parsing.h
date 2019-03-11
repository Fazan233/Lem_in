//
// Created by Vladyslav USLYSTYI on 2019-03-11.
//

#ifndef PARSING_H
#define PARSING_H
#include "lem_in.h"

void	add_to_map(char *str, t_lemin *lem);
int		str_only_digits(char *str);
int 	is_forbidden_chars(char *str);
int		count_delims(char *str, char c);

typedef struct		s_pars
{
	char 			*map;
	int 			iter;
}					t_pars;

#endif

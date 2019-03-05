//
// Created by Vladyslav USLYSTYI on 2019-02-26.
//

#include "lem_in.h"

t_list_lens	*create_list_lens(int len, int repeat)
{
	t_list_lens	*list_lens;

	list_lens = (t_list_lens *) malloc(sizeof(t_list_lens));
	list_lens->next = NULL;
	list_lens->len = len;
	list_lens->repeat = repeat;
	return (list_lens);
}

void		add_to_list_lens(t_list_lens **list_lens, int len, int repeat)
{
	t_list_lens	*tmp;

	tmp = create_list_lens(len, repeat);
	if (*list_lens == NULL)
		*list_lens = tmp;
	else
	{
		tmp->next = *list_lens;
		*list_lens = tmp;
	}
}

int 		is_in_list_mas(t_ways *ways, t_list_lens *list_lens)
{
	int 		len;

	len = ways->len;
	while (list_lens)
	{
		if (list_lens->len == len)
			return (1);
		list_lens = list_lens->next;
	}
	return (0);
}

int 		count_ident_lens(t_ways *ways)
{
	int 		len;
	int 		repeat;

	len = 0;
	repeat = 0;
	while (ways)
	{
		if (ways->len == len)
			repeat++;
		ways = ways->next;
	}
	return (repeat);
}

t_list_lens	*get_list_lens(t_lemin *lem)
{
	t_ways		*ways;
	t_mas_ways	*mas_ways;
	t_list_lens	*list_lens;
	int 		repeat;

	mas_ways = lem->mas_ways;
	while (mas_ways)
	{
		list_lens = NULL;
		ways = mas_ways->ways;
		while (ways)
		{
			if (!is_in_list_mas(ways, list_lens))
			{
				repeat = count_ident_lens(ways);
				add_to_list_lens(&list_lens, ways->len, repeat);
			}
		}
	}
	return (list_lens);
}
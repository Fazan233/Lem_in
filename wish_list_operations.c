//
// Created by Vladyslav USLYSTYI on 2019-03-14.
//

#include "lem_in.h"

void	add_wish_list(t_wish_list **wish, int ant)
{
	t_wish_list	*new_wish;
	t_wish_list	*tmp;

	new_wish = (t_wish_list*)ft_memalloc(sizeof(t_wish_list));
	new_wish->ant = ant;
	if (*wish == NULL)
		*wish = new_wish;
	else
	{
		tmp = *wish;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_wish;
	}
}
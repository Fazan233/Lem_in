//
// Created by Vladyslav USLYSTYI on 2019-03-06.
//

#include "tree.h"

t_p_list	*create_p_list(t_node *node)
{
	t_p_list	*p_list;

	p_list = (t_p_list*)ft_memalloc(sizeof(t_p_list));
	p_list->node = node;
	return (p_list);
}

void		add_to_p_list(t_p_list **p_list, t_p_list *new_p_list)
{
	if (*p_list == NULL)
		*p_list = new_p_list;
	else
	{
		new_p_list->next = *p_list;
		*p_list = new_p_list;
	}
}
//
// Created by Vladyslav USLYSTYI on 2019-03-07.
//

#include "tree.h"

void	del_n_from_p_list(t_p_list **orig, t_p_list *p_list)
{
	t_p_list	*tmp;

	if (p_list == *orig)
	{
		*orig = (*orig)->next;
		free(p_list);
	}
	else
	{
		tmp = *orig;
		while (tmp->next != p_list)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
		free(p_list);
	}
}

void	del_p_list(t_p_list *p_list)
{
	t_p_list	*tmp;

	while (p_list->next)
	{
		tmp = p_list;
		p_list = p_list->next;
		free(tmp);
	}
	free(p_list);
}

t_p_list	*find_p_list(t_p_list *list, t_node *node)
{
	while (list)
	{
		if (list->node == node)
			return (list);
		list = list->next;
	}
	return (list);
}
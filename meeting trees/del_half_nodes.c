//
// Created by Vladyslav USLYSTYI on 2019-03-07.
//

#include "tree.h"

void	del_same_p_lists(t_p_list *p_list, t_node *node)
{
	t_p_list	*tmp;

	while (p_list)
	{
		tmp = find_p_list(p_list->node->next_list, node);
		if (tmp)
			del_n_from_p_list(&p_list->node->next_list, tmp);
		tmp = find_p_list(p_list->node->prev_list, node);
		if (tmp)
			del_n_from_p_list(&p_list->node->prev_list, tmp);
		p_list = p_list->next;
	}
}

int		del_half_nodes(t_node **orig_node, t_node *node, t_lemin *lem)
{
	t_node		*tmp;
	int 		i;

	i = 0;
	while (node)
	{
		tmp = node->next;
		if (node->v != lem->start_vert && node->v != lem->end_vert &&
			(node->next_list == NULL || node->prev_list == NULL))
		{
			i++;
			if (node->next_list == NULL)
				del_same_p_lists(node->prev_list, node);
			else
				del_same_p_lists(node->next_list, node);
			del_node(node, orig_node);
		}
		node = tmp;
	}
	ft_printf("%i\n", i);
	return (i);
}
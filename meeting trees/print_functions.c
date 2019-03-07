//
// Created by Vladyslav USLYSTYI on 2019-03-07.
//

#include "print.h"

void	print_top(t_top_nodes *top_nodes)
{
	while (top_nodes)
	{
		ft_printf("%s ", top_nodes->node->v->name);
		top_nodes = top_nodes->next;
	}
	ft_printf("\b\n");
}

void	print_p_list(t_p_list *p_list)
{
	while (p_list)
	{
		ft_printf("%s ", p_list->node->v->name);
		p_list = p_list->next;
	}
	ft_printf("\b\n");
}

void	print_node_and_links(t_node *node)
{
	if (node)
	{
		ft_printf("%s\n", node->v->name);
		ft_printf("%COLOR -> %i\n", node->v->color);
		ft_printf("NEXT -> ");
		print_p_list(node->next_list);
		ft_printf("PREV -> ");
		print_p_list(node->prev_list);
		ft_printf("\n");
	}
}

void	print_node_and_links_for_all(t_node *node)
{
	while (node)
	{
		print_node_and_links(node);
		node = node->next;
	}
}
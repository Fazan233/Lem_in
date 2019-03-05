//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

t_top_nodes		*create_top_node(t_node *node, t_pretend *pret)
{
	t_top_nodes	*top;

	top = (t_top_nodes*)ft_memalloc(sizeof(t_top_nodes));
	top->node = node;
	top->pretend = pret;
	top->next = NULL;
	return (top);
}

void			add_top_node(t_top_nodes **top, t_top_nodes *new_top)
{
	if (*top == NULL)
		new_top->next = NULL;
	else
		new_top->next = *top;
	*top = new_top;
}

t_top_nodes		*create_top_node_list(t_lema *lema, int	color, t_lemin *lem)
{
	t_top_nodes	*top;
	t_node		*tmp;
	t_pretend	*pretend;

	top = NULL;
	if (lema)
		while (lema)
		{
			pretend = create_pretend_list(lema->node, color, lem->graph);
			add_top_node(&top, create_top_node(lema->node, pretend));
			lema = lema->next;
		}
	else
	{
		tmp = find_node(lem->start_vert, lem->node);
		pretend = create_pretend_list(tmp, color, lem->graph);
		add_top_node(&top, create_top_node(tmp, pretend));
	}
	return (top);
}
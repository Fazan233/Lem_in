//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

void	del_pretend(t_pretend *pret)
{
	t_pretend	*tmp;

	if (pret)
	{
		while (pret->next)
		{
			tmp = pret;
			pret = pret->next;
			free(tmp);
		}
		free(pret);
	}
}

void	del_top_node(t_top_nodes **orig, t_top_nodes *top)
{
	t_top_nodes	*tmp;

	tmp = *orig;
	if (*orig == top)
		*orig = (*orig)->next;
	else
	{
		while (tmp->next != top)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
	}
//	free(top->pretend);
	del_pretend(top->pretend);
	free(top);
}

void	del_top_nodes_list(t_top_nodes **top)
{
	t_top_nodes	*tmp;

	while ((*top)->next)
	{
		tmp = *top;
		*top = (*top)->next;
		del_pretend(tmp->pretend);
		free(tmp);
	}
	del_pretend((*top)->pretend);
	free(*top);
}
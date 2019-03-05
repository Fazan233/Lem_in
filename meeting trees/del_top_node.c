//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

void	del_pretend(t_pretend *pret)
{
	t_pretend	*tmp;

	while (pret->next)
	{
		tmp = pret;
		pret = pret->next;
		free(tmp);
	}
	free(pret);
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
	free(top->pretend);
	free(top);
}
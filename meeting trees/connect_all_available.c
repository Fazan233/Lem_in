//
// Created by Vladyslav USLYSTYI on 2019-03-06.
//

#include "tree.h"
#define	IS_WHITE pret->node->v->color == WHITE

void	connect_available(t_top_nodes *top, int color)
{
	t_pretend	*pret;
	t_node		*current;

	current = top->node;
	pret = top->pretend;
	if (top->pow)
		while (pret)
		{
			if (pret->node->v->color != color && pret->node->v->color != FOUND)
			{
				pret->node->v->color = IS_WHITE ? color : FOUND;
				add_to_p_list(&current->next_list, create_p_list(pret->node));
				add_to_p_list(&pret->node->prev_list, create_p_list(current));
			}
			pret = pret->next;
		}
	else
		while (pret)
		{
			add_to_p_list(&current->next_list, create_p_list(pret->node));
			add_to_p_list(&pret->node->prev_list, create_p_list(current));
			pret = pret->next;
		}
}
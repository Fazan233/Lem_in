//
// Created by Vladyslav USLYSTYI on 2019-03-06.
//

#include "tree.h"
#define	NEED_PNT pret->node->v->color != WHITE && pret->node->v->color != color
#define	IS_WHITE pret->node->v->color == WHITE
//#define IS_FOUND

void	connect_available(t_top_nodes *top, int color)
{
	t_pretend	*pret;
	t_node		*current;

	current = top->node;
	pret = top->pretend;
//	if (top->pow)
//		while (pret)
//		{
//			if (pret->node->v->color != color && pret->node->v->color != FOUND)
//			{
//				pret->node->v->color = IS_WHITE ? color : FOUND;
//				add_to_p_list(&current->next_list, create_p_list(pret->node));
//				add_to_p_list(&pret->node->prev_list, create_p_list(current));
//			}
//			pret = pret->next;
//		}
//	else
//		while (pret)
//		{
//			add_to_p_list(&current->next_list, create_p_list(pret->node));
//			add_to_p_list(&pret->node->prev_list, create_p_list(current));
//			pret = pret->next;
//		}
	while (pret)
		{
			if (color == START && pret->node->v->color != FOUND)
			{
				if (pret->node->v->color == WHITE || pret->node->v->color == color)
					pret->node->v->color = color;
				else
					current->v->color = FOUND;
				add_to_p_list(&current->next_list, create_p_list(pret->node));
				add_to_p_list(&pret->node->prev_list, create_p_list(current));
			}
			else if (color == END && pret->node->v->color != FOUND)
			{
				if (pret->node->v->color == WHITE)
					pret->node->v->color = color;
				else
					current->v->color = FOUND;
				add_to_p_list(&current->prev_list, create_p_list(pret->node));
				add_to_p_list(&pret->node->next_list, create_p_list(current));
			}
//			pret->node->v->color = NEED_PNT ? color : FOUND;
//			IS_WHITE ? pret->node->v->color = color : 0;
//			NEED_PNT ? current->v->color = FOUND : 0;

			pret = pret->next;
		}
}
//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"

void	meet_tree_algo(t_lemin *lem)
{
	t_top_nodes	*top_start;
	t_top_nodes	*top_end;
	t_lema		*lema;

	lema = NULL;
	top_start = create_top_node_list(lema, START, lem);
	lema = create_lema_list(top_start);
}
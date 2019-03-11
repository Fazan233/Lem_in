//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#include "tree.h"
#include <fcntl.h>
#include "lem_in.h"
#include "print.h"


void	first_init(t_lemin *lem)
{
	t_node		*tmp;
	t_pretend	*pretend;

	lem->node = create_node_list(lem->vert);
	lem->top_start = NULL;
	lem->top_end = NULL;

	tmp = find_node(lem->start_vert, lem->node);
	pretend = create_pretend_list(tmp, START, lem);
	add_top_node(&lem->top_start, create_top_node(tmp, pretend));
	lem->top_start->node->v->color = START;

	tmp = find_node(lem->end_vert, lem->node);
	pretend = create_pretend_list(tmp, END, lem);
	add_top_node(&lem->top_end, create_top_node(tmp, pretend));
	lem->top_end->node->v->color = END;
}

static void	init_lem(int fd, t_lemin *lem)
{
	ft_bzero(lem, sizeof(t_lemin));
	parsing(fd, lem);
	lem->start_vert->weight = 0;
	if (lem->start_vert->prev)
	{
		lem->start_vert->prev->next = lem->start_vert->next;
		if (lem->start_vert->next)
			lem->start_vert->next->prev = lem->start_vert->prev;
		lem->start_vert->next = lem->vert;
		lem->start_vert->prev = NULL;
		lem->vert->prev = lem->start_vert;
	}
	lem->vert = lem->start_vert;
	first_init(lem);
//	graph_normalize(lem);
//	lem->list_v = get_list_v(lem, lem->vert);
}


int		step_for_end(t_lemin *lem)
{
//	t_top_nodes	*min;
	t_top_nodes	*tmp;
	t_lema		*lema;

	tmp = lem->top_end;
	while (tmp)
	{
//		count_pow_in_top_nodes(lem->top_end, END);
//		min = get_min_pow_top_node(lem->top_end);
		connect_available(tmp, END);
		tmp = tmp->next;
	}
	lema = create_lema_list(lem->top_end, END);
	del_top_nodes_list(&lem->top_end);
	lem->top_end = create_top_node_list(lema, END, lem);
	del_lema_list(&lema);
	return (lem->top_end ? 1 : 0);
}

int		step_for_start(t_lemin *lem)
{
//	t_top_nodes	*min;
	t_top_nodes	*tmp;
	t_lema		*lema;


	tmp = lem->top_start;
	while (tmp)
	{
//		count_pow_in_top_nodes(lem->top_start, START);
//		min = get_min_pow_top_node(lem->top_start);
		connect_available(tmp, START);
		tmp = tmp->next;
	}
	lema = create_lema_list(lem->top_start, START);
	del_top_nodes_list(&lem->top_start);
	lem->top_start = create_top_node_list(lema, START, lem);
	del_lema_list(&lema);
	return (lem->top_start ? 1 : 0);
}

//int 	maino(void)
//{
//	t_lemin 	*lem;
//	int 		fd;
//
//
////	if (ac)
////		;
////	fd = open(av[1], O_TRUNC | O_RDONLY);
//	fd = open("test", O_RDONLY);
//	lem = (t_lemin*)malloc(sizeof(t_lemin));
//	init_lem(fd, lem);
//	lem->start_node = find_node(lem->start_vert, lem->node);
//	while (1)
//	{
////		ft_printf("TOP START -> ");
////		print_top(lem->top_start);
//		if (!step_for_start(lem))
//			break ;
////		print_node_and_links(lem->top_start->node);
////		ft_printf("TOP END   -> ");
////		print_top(lem->top_end);
//		if (!step_for_end(lem))
//			break ;
//	}

//	del_half_nodes(&lem->node, lem->node, lem);
//	while (del_half_nodes(&lem->node, lem->node, lem))
//		;
////	t_node	*start = find_node(lem->vert, lem->node);
//	print_node_and_links_for_all(lem->node);
//
//	ft_printf("%i\n", count_ways(find_node(lem->end_vert, lem->node), find_node(lem->start_vert, lem->node)   ));
//
//	return 0;
//}
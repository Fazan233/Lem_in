//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#ifndef LEM_IN_H
#define LEM_IN_H
#define INF 2000000000

#include "ft_printf.h"

typedef struct			s_lemin
{
	int					ants;
	struct s_edge		*graph;
	struct s_verticle	*vert;
	struct s_mas_ways	*mas_ways;
	struct s_verticle	*start_vert;
	struct s_verticle	*end_vert;
}						t_lemin;

typedef struct			s_verticle
{
	char				*name;
	struct s_verticle	*next;
	struct s_verticle	*prev;
	struct s_edge		*short_way;
	int					weight;
	int					x;
	int					y;
}						t_verticle;

typedef struct			s_edge
{
	struct s_verticle	*a;
	struct s_verticle	*b;
//	int					name;
	int					available;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_way
{
	struct s_verticle	*vert;
	struct s_way		*next;
	struct s_way		*prev;
	int					ant;
}						t_way;

typedef struct			s_ways
{
	struct s_way		*way;
	struct s_ways		*next;
	int					len;
}						t_ways;

typedef struct			s_mas_ways
{
	int					iter;
	struct s_ways		*ways;
	struct s_mas_ways	*naxt;
}						t_mas_ways;

typedef struct			s_used_vert
{
	struct s_verticle	*vert;
	struct s_used_vert	*next;
}						t_used_vert;

typedef struct			s_partition
{
	t_verticle	*target;
	t_verticle	*iter;
	int			opt;
}						t_partition;

void		swap_2link_item(t_verticle *a, t_verticle *b);
t_verticle	*quick_sort(t_verticle *start, t_verticle *finish);
void		print_list(t_verticle *start, t_verticle *end);
void		add_new_vert(t_verticle **vert, t_verticle *new_vert);
t_verticle	*create_new_vert(char *name);
void	swap_pointer(t_verticle **a, t_verticle **b);
void	quick_sort_for_intmas(int *start, int *finish);
t_verticle		*get_min_vert(t_verticle *v);
void	add_new_vert_to_way(t_way **way, t_verticle *vert);
void	add_new_edge(t_edge **graph, t_edge *edge);
t_edge	*create_edge(t_verticle *a, t_verticle *b);
t_way	*dijkstra(t_verticle *v, t_lemin *lem);

#endif
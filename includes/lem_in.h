//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#ifndef LEM_IN_H
#define LEM_IN_H
#define INF 2000000000
#define ERROR_ALLOCATE "Memory didn't allocate ("

#include "ft_printf.h"


typedef struct			s_lemin
{
	int 				target;

	int 				amount;
	int					ants;
	struct s_edge		*graph;
	struct s_verticle	*vert;
	struct s_mas_ways	*mas_ways;
	struct s_verticle	*start_vert;
	struct s_verticle	*end_vert;
	struct s_list_v		*list_v;
	struct s_mas_res	*mas_res;
	struct s_mas_ways	*big_mas_ways;


	struct s_node		*node;
	struct s_top_nodes	*top_start;
	struct s_top_nodes	*top_end;
	struct s_node		*start_node;
}						t_lemin;

typedef struct			s_verticle
{
	int 				n;
	int 				available;
	int 				gray;
	int 				visited;
	int 				color;
	int 				used;
	int 				light;
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
	struct s_edge		*prev;
}						t_edge;

typedef struct			s_way
{
	struct s_verticle	*vert;
	struct s_edge		*short_way;
	struct s_way		*next;
	struct s_way		*prev;
	int					ant;
}						t_way;

typedef struct			s_ways
{
	struct s_way		*way;
	struct s_ways		*next;
	int					len;
	int 				used;
}						t_ways;

typedef struct			s_mas_ways
{
	int					iter;
	struct s_ways		*ways;
	struct s_mas_ways	*next;
	struct s_list_lens	*lst_lens;
}						t_mas_ways;

typedef struct			s_used_vert
{
	struct s_verticle	*vert;
	struct s_used_vert	*next;
}						t_used_vert;

typedef struct			s_used_edge
{
	struct s_edge		*edge;
	struct s_used_edge	*next;
}						t_used_edge;

typedef struct			s_partition
{
	struct s_verticle	*target;
	struct s_verticle	*iter;
	int					opt;
}						t_partition;

typedef struct 			s_list_v
{
	struct s_verticle	*v;
	struct s_list_e		*list_e;
	struct s_list_v		*next;

}						t_list_v;

typedef struct			s_list_e
{
	struct s_edge		*e;
	struct s_list_e		*next;
}						t_list_e;

typedef struct			s_list_lens
{
	int 				len;
	int 				repeat;
	struct s_list_lens	*next;
}						t_list_lens;

typedef struct			s_min_way
{
	t_way				*way;
	struct s_min_way	*next;
}						t_min_way;

typedef struct			s_mas_res
{
	t_mas_ways			*mas_ways;
	struct s_mas_res	*next;
}						t_mas_res;




t_list_v	*get_list_v(struct s_lemin *lem, struct s_verticle *v);

void		swap_2link_item(t_verticle *a, t_verticle *b);
t_verticle	*quick_sort(t_verticle *start, t_verticle *finish);
void		print_list(t_verticle *start, t_verticle *end);
void		add_new_vert(t_verticle **vert, t_verticle *new_vert);
t_verticle	*create_new_vert(char *name, char *x, char *y);
void	swap_pointer(t_verticle **a, t_verticle **b);
void	quick_sort_for_intmas(int *start, int *finish);
t_verticle		*get_min_vert(t_verticle *v);
void	add_new_vert_to_way(t_way **way, t_verticle *vert, char mode);
void	add_new_edge(t_edge **graph, t_edge *edge);
t_edge	*create_edge(t_verticle *a, t_verticle *b);
t_way	*dijkstra(t_lemin *lem);
void	print_way(t_way *way);
void	add_new_way_to_ways(t_ways **ways, t_way *way, t_lemin *lem, char mode);

t_ways		*find_list_ways1(t_lemin *lem, t_mas_ways *mas_ways);
void	print_ways(t_ways *ways);
void		get_mas_ways(t_lemin *lem);
void	print_mas_ways(t_mas_ways *mas_ways);
void		show_hide_ways(t_ways *ways, int mode, t_lemin *lem);

void		add_to_used_edges(t_used_edge **used, t_edge *e);
void		del_list_edges(t_used_edge **used);

void	parsing(int fd, t_lemin *lem);

int 	get_iter_for_ways(t_ways *ways, int ants);
void	get_iters(t_mas_ways *mas_ways, t_lemin *lem);
void	print_min_mas_ways(t_mas_ways *mas_ways);

void		bubble_sort_list(t_ways **begin);
void 	graph_normalize(t_lemin *lem);
int		del_single(t_edge **orig_edge, t_verticle **orig_v);
t_list_e	*find_list_e(t_list_v *list_v, t_verticle *v);
t_way	*get_short_way(t_lemin *lem);
t_ways		*find_list_ways2(t_lemin *lem, t_mas_ways *mas_ways);
int			get_iter(t_ways *ways, int ants);
t_min_way	*get_min_way_list(t_mas_ways *mas_ways);
void	del_list_min_way(t_min_way **min_way);
void		bubble_sort_list_l_u(t_ways **begin);
void		bubble_sort_list_u_l(t_ways **begin);
int 	count_amount_rooms(t_lemin *lem);

t_way	*get_short_way_e(t_lemin *lem);
t_way	*get_short_way_s(t_lemin *lem);

t_ways		*find_list_ways_s(t_lemin *lem, t_mas_ways *mas_ways);
t_ways		*find_list_ways_e(t_lemin *lem, t_mas_ways *mas_ways);

void		add_to_mas_res(t_mas_res **mas_res, t_mas_ways *res);
void		add_to_mas_ways(t_mas_ways **mas_ways, t_ways *ways);
void	del_mas_ways(t_mas_ways **mas_ways, t_mas_ways *exept);
void		write_result(t_lemin *lem, int algo);
t_mas_ways		*get_result(t_mas_res *res);
void	print_result(t_mas_ways *res, target);
t_mas_ways		*get_min_mas_ways(t_mas_ways *mas_ways);

#endif
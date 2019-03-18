//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#ifndef LEM_IN_H
#define LEM_IN_H
#define ERROR_ALLOCATE "Memory didn't allocate ("
#define ERROR "ERROR"
#define FLAG_LIST "ewamgitL"

#include "ft_printf.h"

typedef struct			s_qlist
{
	struct s_verticle	*v;
	struct s_qlist		*next;
	struct s_qlist		*prev;
}						t_qlist;

typedef struct			s_queue
{
	struct s_qlist		*qlist;
	struct s_qlist		*last;
}						t_queue;

typedef struct			s_wish_list
{
	int 				ant;
	struct s_wish_list	*next;
}						t_wish_list;

typedef struct			s_ant
{
	struct s_way		*way;
}						t_ant;

typedef struct			s_flags
{
	unsigned int		lem:1;
	unsigned int 		debug:1;
	unsigned int 		ways:1;
	unsigned int 		all:1;
	unsigned int		map:1;
	unsigned int		go:1;
	unsigned int		iter:1;
	unsigned int		target:1;
}						t_flags;

typedef struct			s_pars
{
	char 				*map;
	int 				iter;
}						t_pars;

typedef struct			s_lemin
{
	struct s_flags		flag;
	int 				target;
	int 				amount;
	int					ants;
	struct s_queue		queue;
	struct s_edge		*graph;
	struct s_verticle	*vert;
	struct s_mas_ways	*mas_ways;
	struct s_mas_ways	*result;
	struct s_verticle	*start_vert;
	struct s_verticle	*end_vert;
	struct s_list_v		*list_v;
	struct s_mas_res	*mas_res;
	struct s_pars		pars;
	struct s_ant		*list_ants;
	struct s_wish_list	*wish_list;
}						t_lemin;

typedef struct			s_verticle
{
	int 				gray:1;
	int 				visited:1;
	int 				block:1;
	int 				mult:1;
	int 				n;
	int					weight;
	int					x;
	int					y;
	char				*name;
	struct s_verticle	*next;
	struct s_verticle	*prev;
	struct s_edge		*short_way;
}						t_verticle;

typedef struct			s_edge
{
	int					available;
	struct s_verticle	*a;
	struct s_verticle	*b;
	struct s_edge		*next;
	struct s_edge		*prev;
}						t_edge;

typedef struct			s_way
{
	int					ant;
	struct s_verticle	*vert;
	struct s_edge		*short_way;
	struct s_way		*next;
	struct s_way		*prev;
}						t_way;

typedef struct			s_ways
{
	int					len;
	int 				used;
	struct s_way		*way;
	struct s_ways		*next;
}						t_ways;

typedef struct			s_mas_ways
{
	int					iter;
	struct s_ways		*ways;
	struct s_mas_ways	*next;
}						t_mas_ways;

typedef struct 			s_list_v
{
	struct s_list_e		*list_e;
	struct s_list_v		*next;

}						t_list_v;

typedef struct			s_list_e
{
	struct s_edge		*e;
	struct s_list_e		*next;
}						t_list_e;

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

void		check_sharp(t_lemin *lem, char **line, int fd);

void		add_wish_list(t_wish_list **wish, int ant);
void		check_flags(int ac, char **av, t_lemin *lem);
void		print_mas_ways(t_mas_ways *mas_ways);
void		print_data(t_lemin *lem);
void		ft_error_mode(char *std_mess, char *mode_mess, int mode);
void		print_list_ants(t_lemin *lem);
void		print_choosed_ant(t_lemin *lem);
void		p_ants_go(t_ways *ways, t_lemin *lem, int ant);
void		help(char *help);
t_verticle	*pop_queue(t_queue *queue);
void		push_queue(t_queue *queue, t_verticle *v);
t_way		*bfs(t_lemin *lem);
void 		del_queue_list(t_queue *queue);


t_list_v	*get_list_v(struct s_lemin *lem, struct s_verticle *v);
void		add_new_vert(t_verticle **vert, t_verticle *new_vert);
t_verticle	*create_new_vert(char *name, int x, int y);
void		add_new_vert_to_way(t_way **way, t_verticle *vert);
void		add_new_edge(t_edge **graph, t_edge *edge);
t_edge		*create_edge(t_verticle *a, t_verticle *b);
void		print_way(t_way *way);
void		add_new_way_to_ways(t_ways **ways, t_way *way, t_lemin *lem);
void		print_ways(t_ways *ways);
void		parsing(int fd, t_lemin *lem);
void		get_iters(t_mas_ways *mas_ways, t_lemin *lem);
t_way		*get_short_way(t_lemin *lem);
int			get_iter(t_ways *ways, int ants);
t_min_way	*get_min_way_list(t_mas_ways *mas_ways);
void		del_list_min_way(t_min_way **min_way);
void		bubble_sort_list_l_u(t_ways **begin);
t_ways		*find_list_ways(t_lemin *lem, t_mas_ways *mas_ways);
void		add_to_mas_res(t_mas_res **mas_res, t_mas_ways *res);
void		add_to_mas_ways(t_mas_ways **mas_ways, t_ways *ways);
void		del_mas_ways(t_mas_ways **mas_ways, t_mas_ways *exept);
void		write_result(t_lemin *lem);
t_mas_ways	*get_result(t_mas_res *res);
int 		count_amount_rooms(t_lemin *lem);
void		print_result(t_mas_ways *res, int target);
t_mas_ways	*get_min_mas_ways(t_mas_ways *mas_ways);
int 		number_can_way(t_ways *ways, t_ways *begin);
void 		is_valid_link(t_lemin *lem, char **line);
void		room_validation(t_lemin *lem, char ***mas);
void		add_to_map(char *str, t_lemin *lem);
int			is_valid_room(t_lemin *lem, char **line);
int 		get_target(char *str);
int			str_only_digits(char *str);
int 		is_forbidden_chars(char *str);
int			count_delims(char *str, char c);
void		ft_error(char *message);
void		parsing(int fd, t_lemin *lem);
void		ants_go(t_ways *ways, t_lemin *lem, int ant);
void		ants_go_one_way(t_lemin *lem);

#endif
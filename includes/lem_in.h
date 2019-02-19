//
// Created by Vladyslav USLYSTYI on 2019-02-18.
//

#ifndef LEM_IN_H
#define LEM_IN_H

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
	int					name;
	int					available;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_way
{
	int					len;
	struct s_verticle	*vert;
	struct s_way		*next;
	struct s_way		*prev;
	int					ant;
}						t_way;

typedef struct			s_ways
{
	struct s_way		*way;
	struct s_ways		*next;
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

void		swap_2link_item(t_verticle **a, t_verticle **b);
void		quick_sort(t_verticle *start, t_verticle *finish);

#endif

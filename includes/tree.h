//
// Created by Vladyslav USLYSTYI on 2019-03-05.
//

#ifndef LEM_IN_TREE_H
# define LEM_IN_TREE_H

# define WHITE 0
# define START 1
# define END 2
# define FOUND 3
# include "lem_in.h"

typedef struct			s_p_list
{
	struct s_node		*s_node;
	struct s_p_list		*next;
}						t_p_list;

typedef struct      	s_node
{
	struct s_verticle	*v;
	struct s_p_list		*prev_list;
	struct s_p_list 	*next_list;
	struct s_node		*next;
	struct s_node		*prev;
}                   	t_node;

typedef struct			s_top_nodes
{
	int 				pow;
	struct s_node		*node;
	struct s_pretend	*pretend;
	struct s_top_nodes	*next;
}						t_top_nodes;

typedef struct			s_lema
{
	struct s_node		*node;
	struct s_lema		*next;
}						t_lema;

typedef struct			s_pretend
{
	struct s_node		*node;
	struct s_pretend	*next;
}						t_pretend;

t_node			*find_node(t_verticle *v, t_node *node);
t_pretend		*create_pretend_list(t_node *node, int color, t_edge *edge);
t_top_nodes		*create_top_node_list(t_lema *lema, int	color, t_edge *edge);


#endif

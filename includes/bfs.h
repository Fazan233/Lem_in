//
// Created by Vladyslav USLYSTYI on 2019-03-08.
//

#ifndef LEM_IN_BFS_H
#define LEM_IN_BFS_H

#include "lem_in.h"

typedef struct		s_qlist
{
	t_verticle		*v;
	struct s_qlist	*next;
	struct s_qlist	*prev;
}					t_qlist;

typedef struct		s_queue
{
	struct s_qlist	*qlist;
	struct s_qlist	*last;
}					t_queue;

t_verticle	*pop_queue(t_queue *queue);
void		*push_queue(t_queue *queue, t_verticle *v);
t_way		*bfs(t_lemin *lem);

#endif //LEM_IN_BFS_H

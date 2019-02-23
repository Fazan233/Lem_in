#include <fcntl.h>
#include "lem_in.h"

t_verticle	*find_vert(t_verticle *v, char *name)
{
	while (v)
	{
		if (!ft_strcmp(v->name, name))
			return (v);
		v = v->next;
	}
	return (NULL);
}

int main()
{
	t_verticle	*vert;
	t_edge		*graph;
	int 		fd;
	char 		*line;
	fd = open("verts", O_RDONLY);
	vert = NULL;
	graph = NULL;
	while (get_next_line(fd, &line) > 0)
		add_new_vert(&vert, create_new_vert(line));
//	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "2")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "2"), find_vert(vert, "5")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "6")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "4")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "4"), find_vert(vert, "7")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "5"), find_vert(vert, "6")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "6"), find_vert(vert, "8")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "7"), find_vert(vert, "8")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "3")));

	add_new_edge(&graph, create_edge(find_vert(vert, "4"), find_vert(vert, "5")));
	add_new_edge(&graph, create_edge(find_vert(vert, "6"), find_vert(vert, "4")));
	add_new_edge(&graph, create_edge(find_vert(vert, "6"), find_vert(vert, "5")));
	add_new_edge(&graph, create_edge(find_vert(vert, "2"), find_vert(vert, "4")));
	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "5")));
	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "4")));
	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "2")));
	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "3")));


	t_lemin *lem = (t_lemin*)malloc(sizeof(t_lemin));
	lem->vert = vert;
	lem->start_vert = find_vert(vert, "1");
	lem->end_vert = find_vert(vert, "6");
	lem->graph = graph;
//	graph->available = 0;
	lem->mas_ways = NULL;
	lem->used = NULL;
	get_mas_ways(lem);
	print_mas_ways(lem->mas_ways);
//	print_list(vert, vert->prev);
//	vert = quick_sort(vert, vert->prev);
//	print_list(vert, vert->prev);


	return 0;
}
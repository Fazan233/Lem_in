#include <fcntl.h>
#include "lem_in.h"
#define SIZE 10

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
	srandom(836661);
	fd = open("verts", O_RDONLY);
	vert = NULL;
	graph = NULL;
	while (get_next_line(fd, &line) > 0)
		add_new_vert(&vert, create_new_vert(line));
	add_new_edge(&graph, create_edge(find_vert(vert, "s"), find_vert(vert, "1")));
	add_new_edge(&graph, create_edge(find_vert(vert, "s"), find_vert(vert, "3")));
	add_new_edge(&graph, create_edge(find_vert(vert, "s"), find_vert(vert, "5")));
	add_new_edge(&graph, create_edge(find_vert(vert, "4"), find_vert(vert, "3")));
	add_new_edge(&graph, create_edge(find_vert(vert, "2"), find_vert(vert, "1")));
	add_new_edge(&graph, create_edge(find_vert(vert, "5"), find_vert(vert, "6")));
	add_new_edge(&graph, create_edge(find_vert(vert, "2"), find_vert(vert, "4")));
	add_new_edge(&graph, create_edge(find_vert(vert, "2"), find_vert(vert, "e")));
	add_new_edge(&graph, create_edge(find_vert(vert, "6"), find_vert(vert, "e")));

	t_lemin *lem = (t_lemin*)malloc(sizeof(t_lemin));
	lem->vert = vert;
	lem->start_vert = find_vert(vert, "s");
	lem->end_vert = find_vert(vert, "e");
	lem->graph = graph;

	t_way *way = dijkstra(vert, lem);
//	print_list(vert, vert->prev);
//	vert = quick_sort(vert, vert->prev);
//	print_list(vert, vert->prev);


	return 0;
}
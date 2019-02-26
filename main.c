#include <fcntl.h>
#include "lem_in.h"
#include "test.h"

//t_verticle	*find_vert(t_verticle *v, char *name)
//{
//	while (v)
//	{
//		if (!ft_strcmp(v->name, name))
//			return (v);
//		v = v->next;
//	}
//	return (NULL);
//}

char	*ctoa(char c)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}

void	init_lem(int fd, t_lemin *lem)
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
		lem->vert->prev = lem->start_vert; //kostyl
	}
	lem->vert = lem->start_vert;
	lem->list_v = get_list_v(lem, lem->vert);
}

int main()
{
	t_lemin 	*lem;
	int 		fd;

	fd = open("superpos.txt", O_RDONLY);
	lem = (t_lemin*)malloc(sizeof(t_lemin));
	init_lem(fd, lem);

	get_mas_ways(lem);

	print_mas_ways(lem->mas_ways);
//	t_verticle	*vert;
//	t_edge		*graph;
//	int 		fd;
//	char 		*line;
//	fd = open("verts", O_RDONLY);
//	vert = NULL;
//	graph = NULL;
//	while (get_next_line(fd, &line) > 0)
//		add_new_vert(&vert, create_new_vert(line));
//	int i;
//	i = 0;
//	while (i < 5)
//		add_new_vert(&vert, create_new_vert(ft_itoa(i++)));

//	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "2")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "2"), find_vert(vert, "5")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "6")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "4")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "4"), find_vert(vert, "7")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "5"), find_vert(vert, "6")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "6"), find_vert(vert, "8")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "7"), find_vert(vert, "8")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "3")));

//	t_verticle *s;
//	t_verticle *f;
//
//	int count = 0;
//	t_lemin *lem = (t_lemin*)malloc(sizeof(t_lemin));
//	lem->vert = vert;
//	lem->start_vert = find_vert(vert, "4");
//	lem->end_vert = find_vert(vert, "0");
//
//	s = lem->start_vert;
//	while (s != lem->end_vert)
//	{
//		f = s->next;
//		while (f != lem->end_vert)
//		{
//			count++;
//			add_new_edge(&graph, create_edge(find_vert(vert, s->name), find_vert(vert, f->name)));
//			f = f->next;
//		}
//		count++;
//		add_new_edge(&graph, create_edge(find_vert(vert, s->name), find_vert(vert, f->name)));
//		s = s->next;
//	}

//	add_new_edge(&graph, create_edge(find_vert(vert, "4"), find_vert(vert, "5")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "6"), find_vert(vert, "4")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "6"), find_vert(vert, "5")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "2"), find_vert(vert, "4")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "5")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "3"), find_vert(vert, "4")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "2")));
//	add_new_edge(&graph, create_edge(find_vert(vert, "1"), find_vert(vert, "3")));



//	lem->graph = graph;
//	graph->available = 0;
//	lem->mas_ways = NULL;
//	lem->used = NULL;
//	print_list(vert, vert->prev);
//	vert = quick_sort(vert, vert->prev);
//	print_list(vert, vert->prev);


	return 0;
}
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

	fd = open("test.txt", O_RDONLY);
	lem = (t_lemin*)malloc(sizeof(t_lemin));
	init_lem(fd, lem);

	get_mas_ways(lem);

	print_mas_ways(lem->mas_ways);
	return 0;
}
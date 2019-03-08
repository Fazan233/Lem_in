#include <fcntl.h>
#include "lem_in.h"

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

static void	init_lem(int fd, t_lemin *lem)
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
		lem->vert->prev = lem->start_vert;
	}
	lem->vert = lem->start_vert;
//	graph_normalize(lem);
	lem->list_v = get_list_v(lem, lem->vert);
}

t_ways	*get_min_ways(t_mas_ways *mas_ways)
{
	t_mas_ways	*min;

	min = mas_ways;
	while (mas_ways)
	{
		if (mas_ways->iter < min->iter)
			min = mas_ways;
		mas_ways = mas_ways->next;
	}
	return (min->ways);
}

void	go_ants_in_way(t_way *way, t_lemin *lem, int *steps, int len)
{
	t_way	*end;

	end = way->prev;
	while (end->prev != way)
	{
		if (end->prev->ant)
		{
			ft_printf("L%d-%s ", end->prev->ant, end->vert->name);
			end->ant = end->prev->ant;
			end->prev->ant = 0;
			(*steps)++;
		}
		end = end->prev;
	}
	if (lem->ants && lem->ants >= len)
	{
		ft_printf("L%d-%s ", lem->ants, end->vert->name);
		end->ant = lem->ants;
		lem->ants--;
		(*steps)++;
	}
}

void	set_optional_lens_in_ways(t_ways *ways)
{
	t_ways	*begin;
	int 	min;

	begin = ways;
	min = ways->len;
	while (ways)
	{
		if (min > ways->len)
			min = ways->len;
		ways = ways->next;
	}
	min--;
	ways = begin;
	while (ways)
	{
		ways->len = ways->len - min;
		ways = ways->next;
	}
}

void	ants_go(t_ways *ways, t_lemin *lem)
{
	t_ways	*begin;
	int 	steps;
	int 	i;

	i = 0;

	steps = 1;
//	set_optional_lens_in_ways(ways);
	begin = ways;
	while (steps)
	{
		steps = 0;
		ways = begin;
		while (ways)
		{
			go_ants_in_way(ways->way, lem, &steps, ways->len);
			ways = ways->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("{RED}%i iters\n{EOC}", i - 1);
}


void	sort_mas_ways(t_mas_ways *mas_ways)
{
	while (mas_ways)
	{
		bubble_sort_list(&mas_ways->ways);
		mas_ways = mas_ways->next;
	}
}


int main()
//int main(int ac, char **av)
{
	t_lemin 	*lem;
	int 		fd;


//	if (ac)
//		;
//	fd = open(av[1], O_TRUNC | O_RDONLY);
	fd = open("test", O_RDONLY);
	lem = (t_lemin*)malloc(sizeof(t_lemin));
	init_lem(fd, lem);

	get_mas_ways(lem);
//	sort_mas_ways(lem->mas_ways);
	get_iters(lem->mas_ways, lem);
	print_mas_ways(lem->mas_ways);

//	print_min_mas_ways(lem->mas_ways);
//	ants_go(get_min_ways(lem->mas_ways), lem);
	return 0;
}
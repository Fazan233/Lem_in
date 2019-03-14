//
// Created by User on 19.02.2019.
//

#include "lem_in.h"

void	print_way(t_way *way)
{
	t_way	*end;

	if (way)
	{
		end = way->prev;
		while (1)
		{
			if (way == end)
			{
				ft_printf("{RED}%s{EOC}\n", way->vert->name);
				break ;
			}
			if (way == end->next)
				ft_printf("{GREEN}%s{EOC} -> ", way->vert->name);
			else
				ft_printf("{YELLOW}%s{EOC} -> ", way->vert->name);
			way = way->next;
		}
	}
	else
		ft_printf("The way is not exist\n");
}

void	print_ways(t_ways *ways)
{
	if (ways)
	{
		ft_printf(" {YELLOW}Lenght{EOC} | {YELLOW}Parallel Ways{EOC}\n");
		ft_printf("-------------------------------\n");
		while (ways)
		{
			ft_printf("{CYAN}%7d{EOC} | ", ways->len);
			print_way(ways->way);
			ways = ways->next;
		}
		ft_printf("-------------------------------\n\n");
	}
	else
		ft_printf("The ways is not exist\n");
}

void	print_mas_ways(t_mas_ways *mas_ways)
{
	if (mas_ways)
	{
		while (mas_ways)
		{
			ft_printf("{YELLOW}iters - %d{EOC}\n", mas_ways->iter);
			print_ways(mas_ways->ways);
			mas_ways = mas_ways->next;
		}
		ft_printf("\n");
	}
}

void	print_min_mas_ways(t_mas_ways *mas_ways)
{
	t_mas_ways	*min;

	min = mas_ways;
	while (mas_ways)
	{
		if (mas_ways->iter < min->iter)
			min = mas_ways;
		mas_ways = mas_ways->next;
	}
	ft_printf("{YELLOW}iters - %d{EOC}\n", min->iter);
	print_ways(min->ways);
}

void	print_result(t_mas_ways *res, int target)
{
	ft_printf("{YELLOW}iters - %d{EOC}   {RED}target - %d{EOC}\n",
			res->iter, target);
	print_ways(res->ways);
}

void	print_list_ants(t_lemin *lem)
{
	int 		i;
	int 		ant;

	i = 0;
	ant = lem->ants;
	p_ants_go(lem->result->ways, lem, lem->ants);
	lem->ants = ant;
	while (i < lem->ants)
	{
		ft_printf("L%-4d | ", i + 1);
		print_way(lem->list_ants[i].way);
		i++;
	}
	ft_printf("\n");
}

void	print_choosed_ant(t_lemin *lem)
{
	t_wish_list	*wish;
	int 		ant;

	wish = lem->wish_list;
	ant = lem->ants;
	p_ants_go(lem->result->ways, lem, lem->ants);
	lem->ants = ant;
	while (wish)
	{
		ft_printf("L%-4d | ", wish->ant);
		if (wish->ant > 0 && wish->ant <= lem->ants)
			print_way(lem->list_ants[wish->ant - 1].way);
		else
			ft_printf("{RED}THE ANT IS NOT EXIST!{EOC}\n");
		wish = wish->next;
	}
	ft_printf("\n");
}
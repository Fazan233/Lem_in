/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:05:53 by vuslysty          #+#    #+#             */
/*   Updated: 2019/03/18 14:12:27 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_way(t_way *way)
{
	t_way		*end;

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

void	print_list_ants(t_lemin *lem)
{
	int			i;
	int			ant;

	i = 0;
	ant = lem->ants;
	if (lem->flag.go == 0)
		p_ants_go(lem->result->ways, lem, lem->ants);
	lem->ants = ant;
	ft_printf("{YELLOW}Ant num{EOC} | {YELLOW}Ant's way{EOC}\n");
	ft_printf("-------------------------------\n");
	while (i < lem->ants)
	{
		ft_printf("{PURPLE} L%-4d{EOC}  | ", i + 1);
		print_way(lem->list_ants[i].way);
		i++;
	}
	ft_printf("-------------------------------\n");
	ft_printf("\n");
}

void	print_choosed_ant(t_lemin *lem)
{
	t_wish_list	*wish;
	int			ant;

	wish = lem->wish_list;
	ant = lem->ants;
	if (lem->flag.go == 0)
		p_ants_go(lem->result->ways, lem, lem->ants);
	lem->ants = ant;
	ft_printf("{YELLOW}Ant num{EOC} | {YELLOW}Ant's way{EOC}\n");
	ft_printf("-------------------------------\n");
	while (wish)
	{
		ft_printf("{PURPLE} L%-4d{EOC}  | ", wish->ant);
		if (wish->ant > 0 && wish->ant <= lem->ants)
			print_way(lem->list_ants[wish->ant - 1].way);
		else
			ft_printf("{RED}THE ANT IS NOT EXIST!{EOC}\n");
		wish = wish->next;
	}
	ft_printf("-------------------------------\n");
	ft_printf("\n");
}

//
// Created by Vladyslav USLYSTYI on 2019-02-28.
//

#include "lem_in.h"

//int 	get_iter_for_ways(t_ways *ways, int ants)
//{
//	int 	*mas;
//	int 	i;
//	int 	counter;
//	int 	add;
//
//	mas = create_mas(ways);
////	pr_mas(mas);
//	add = get_add(mas);
////	pr_mas(mas);
//	counter = 0;
//	while (1)
//	{
//		i = 0;
//		if (ants == 0)
//			break ;
//		while (mas[i] != 0)
//			if (i == 0 || mas[i] <= ants)
//			{
//				i++;
//				ants--;
//			}
//			else
//				break ;
//		counter++;
//	}
//	return (counter + add);
//}

//void	get_iters(t_mas_ways *mas_ways, t_lemin *lem)
//{
//	while (mas_ways)
//	{
//		mas_ways->iter = get_iter_for_ways(mas_ways->ways, lem->ants);
//		mas_ways = mas_ways->next;
//	}
//}

int 	number_can_way(t_ways *ways, t_ways *begin)
{
	int min;
	int	sum;

	sum = 0;
	while (begin != ways)
	{
		min = begin->len;
		sum = sum + (ways->len - min);
		begin = begin->next;
	}
	return (sum);
}

int		get_iter(t_ways *ways, int ants)
{
	int 	counter;
	t_ways	*begin;
	int 	tmp;

	begin = ways;
	counter = 0;
	while (ants)
	{
		ways = begin;
		while (ways)
		{
			tmp = number_can_way(ways, begin);
			if (ants > tmp)
				ants--;
			else
				break ;
			ways = ways->next;
		}
		counter++;
	}
	return (counter - 1 + begin->len);
}

void	get_iters(t_mas_ways *mas_ways, t_lemin *lem)
{
	while (mas_ways)
	{
		bubble_sort_list(&mas_ways->ways);
		mas_ways->iter = get_iter(mas_ways->ways, lem->ants);
		mas_ways = mas_ways->next;
	}
}







































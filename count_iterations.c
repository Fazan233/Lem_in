//
// Created by Vladyslav USLYSTYI on 2019-02-28.
//

#include "lem_in.h"

int		turn_off_uses_and_get_count(t_ways *ways)
{
	int		i;

	i = 0;
	while (ways)
	{
		i++;
		ways->used = 0;
		ways = ways->next;
	}
	return (i);
}

int 	get_min_way(t_ways *ways)
{
	t_ways	*min;

	min = ways;
	while (ways)
	{
		if ((ways->used == 0 && min->len > ways->len) || min->used == 1)
			min = ways;
		ways = ways->next;
	}
	if (min->used == 1)
		return (0);
	else
	{
		min->used = 1;
		return (min->len);
	}
}

int 	*create_mas(t_ways *ways)
{
	int		*mas;
	int 	count;
	int		i;

	count = turn_off_uses_and_get_count(ways);
	mas = (int*)ft_memalloc(sizeof(int) * (count + 1));
	i = 0;
	while (i < count)
		mas[i++] = get_min_way(ways);
	mas[i] = 0;
	return (mas);
}

int 	get_add(int *mas)
{
	int 	add;

	add = *mas - 1;
	while (*mas)
	{
		*mas = *mas - add;
		mas++;
	}
	return (add);
}

void	pr_mas(int *mas)
{
	while (*mas)
	{
		ft_printf("%d ", *mas);
		mas++;
	}
	ft_printf("\n");
}

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

//take len - 1
void	set_values_minus_min(t_ways *ways, int min, int mode)
{
	while (ways)
	{
		if (mode == 0)
			ways->len = ways->len - (min - 1);
		else
			ways->len = ways->len + (min - 1);
		ways = ways->next;
	}
}

int 	number_can_way(t_ways *ways, t_ways *begin, int min)
{
	int	sum;

	sum = 0;
	while (begin != ways)
	{
		sum = sum + (begin->len - min);
		begin = begin->next;
	}
	return (sum + (begin->len - min));
}

int		get_iter(t_ways *ways, int ants)
{
	int 	min;
	int 	counter;
	t_ways	*begin;
	int 	tmp;

	begin = ways;
	counter = 0;
	min = ways->len;
//	set_values_minus_min(ways, min, 0);
	while (ants)
	{
		ways = begin;
		while (ways)
		{
			tmp = number_can_way(ways, begin, min);
			if (ants > tmp)
				ants--;
			else
				break ;
			ways = ways->next;
		}
		counter++;
	}
//	set_values_minus_min(ways, min, 1);
	return (counter + min - 1);
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






































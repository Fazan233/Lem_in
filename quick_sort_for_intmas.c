//
// Created by Vladyslav USLYSTYI on 2019-02-20.
//

#include <lem_in.h>

static void	swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int			*partition(int *s, int *f)
{
	int		opt;

	opt = 1;
	while (1)
	{
		if (s == f)
			break ;
		if ((opt == 1 && *s > *f) || (opt == 0 && *s > *f))
		{
			swap_int(s, f);
			opt = !opt;
		}
		if (opt)
			f = f + 1;
		else
			s = s + 1;
	}
	return (s);
}

void	quick_sort_for_intmas(int *start, int *finish)
{
	int		*elem;

	elem = partition(start, finish);
	if (elem != start)
		quick_sort_for_intmas(start, elem - 1);
	if (elem != finish)
		quick_sort_for_intmas(elem + 1, finish);
}
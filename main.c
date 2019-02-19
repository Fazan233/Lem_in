#include <ft_printf.h>
#include "lem_in.h"

int main()
{
	t_verticle lst[5];
	t_verticle *ls;

	lst[0].next = &lst[1];
	lst[1].next = &lst[2];
	lst[2].next = &lst[3];
	lst[3].next = &lst[4];
	lst[4].next = &lst[0];

	lst[0].prev = &lst[4];
	lst[1].prev = &lst[0];
	lst[2].prev = &lst[1];
	lst[3].prev = &lst[2];
	lst[4].prev = &lst[3];

	lst[0].weight = 25;
	lst[1].weight = 11;
	lst[2].weight = 83;
	lst[3].weight = 23;
	lst[4].weight = 32;

	quick_sort(&lst[0], &lst[4]);
	int i = 0;
	ls = &lst[1];
	while (i < 5)
	{
		ft_printf("%d\n", ls->weight);
		ls = ls->next;
		i++;
	}
	return 0;
}
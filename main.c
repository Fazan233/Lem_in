#include <fcntl.h>
#include "lem_in.h"
#define SIZE 10



int main()
{
//	t_verticle	*vert;
//	int 		fd;
////	char 		*line;
//	srandom(836661);
//	fd = open("verts", O_RDONLY);
//	vert = NULL;
//	unsigned long i = 0;
//	while (i < 10000)
//	{
//		add_new_vert(&vert, create_new_vert(random() % 20));
//		i++;
//	}
//	print_list(vert, vert->prev);
//	vert = quick_sort(vert, vert->prev);
//	print_list(vert, vert->prev);

	int *mas;
	int i;

	mas = (int*)malloc(sizeof(int) * SIZE);
	i = 0;
	while (i < SIZE)
	{
		mas[i] = random() % 10000;
		i++;
	}
	quick_sort_for_intmas(mas, mas + SIZE - 1);
	i = 0;
	while (i < SIZE)
	{
		ft_printf("%d ", mas[i]);
		i++;
	}
	return 0;
}
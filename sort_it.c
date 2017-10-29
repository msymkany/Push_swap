#include "push.h"

void    sort_three_max(t_stack *a, int len_a)
{
	while (len_a > 1)
	{
		if (a->num > a->next->num)
		{
			if (a->next->next && a->num > a->next->next->num &&
					ft_printf("ra\n"))
				ra(&a);
			else
			{
				sa(&a);
				ft_printf("sa\n");
			}
		}
		else if (a->next->next && a->next->next->num < a->next->num
				&& ft_printf("rra\n"))
			rra(&a);
		len_a--;
	}
}

void    sort_it(t_stack *a, int len_a, t_stack *b)
{
	t_head  *st_a;
	t_head  *st_b;

	if (len_a > 3)
	{
		st_a = (t_head *)ft_memalloc(sizeof(t_head));
		st_b = (t_head *)ft_memalloc(sizeof(t_head));
		st_a->self = a;
		st_a->len = len_a;
		ft_printf("%s\n", st_b->self); //test
		st_b->self = b; // test
		write(1, "quicksort here\n", 15);
//		quick_sort();
	}
	else
		sort_three_max(a, len_a);
}

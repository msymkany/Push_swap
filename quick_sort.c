/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:59:40 by msymkany          #+#    #+#             */
/*   Updated: 2017/11/20 15:59:44 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#define CURRNUM x->a->num
#define NEXTNUM x->a->next->num
#define THIRDNUM x->a->next->next->num
#define THIRD x->a->next->next
#define CURRNUMB x->b->num
#define NEXTNUMB x->b->next->num
#define ALEN x->len_a
#define BLEN x->len_b

void	sort_short(t_all *x, int len_a, int len_b)
{
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (len_a == 3)
		add_op_new(x, "ra");
	if (len_b == 3)
		add_op_new(x, "rrb");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (len_a == 3)
		add_op_new(x, "rra");
	if (len_b == 3) //here
		add_op_new(x, "rrb");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");

}

int     divide_b(t_all *x, int len)
{
	int 	med;
	int     pa;
	int		rb;

	pa = 0;
	rb = 0;
	med = get_median(x->b, len);
	while (pa < len / 2)
	{
		if (CURRNUMB >= med)
		{
			add_op_new(x, "pa");
			pa++;
		}
		else
		{
			add_op_new(x, "rb");
			rb++;
		}
	}
	//reflect, what was pushed
//	sort_a(x, 0);
	if (rb && rb < (pa - rb))
		while (rb--)
			add_op_new(x, "rrb");
	else
		while (rb++ <= pa)
			add_op_new(x, "rb");
	return (pa);
}

int     divide_a(t_all *x, int len)
{
	int 	med;
	int     pb;
	int		ra;

	pb = 0;
	ra = 0;
	med = get_median(x->a, len);
	while (pb < len / 2)
	{
		if (CURRNUM < med)
		{
			add_op_new(x, "pb");
			pb++;
		}
		else
		{
			add_op_new(x, "ra");
			ra++;
		}
	}
	if (ra && ra < (pb - ra))
		while (ra--)
			add_op_new(x, "rra");
	else
		while (ra++ <= pb)
			add_op_new(x, "ra");
	return (pb);
}

void	sort_b(t_all *x, int len_a, int len_b, int push)
{
	if (len_b <= 3)
	{
		sort_short(x, len_a, len_b);
		while (push-- > 0)
		{
			add_op_new(x, "pb");
		}
	}
	if (len_b <= 3 || stack_b_sorted(x->b))
		return ;
	sort_a(x, len_a + push, len_b - push, push);
	if (len_b > 3 && !stack_b_sorted(x->b))
	{
		push = divide_b(x, len_b);
	}
	sort_b(x, len_a + push, len_b - push, push);
}

void	sort_a(t_all *x, int len_a, int len_b, int push)
{
//	add_op(&(x->op), "sa", &(x->a), &(x->b)); // test
//	add_op_new(x, "rrr"); // test
	if (len_a <= 3)
	{
		sort_short(x, len_a, len_b);
		while (push-- > 0)
			add_op_new(x, "pa");
	}
	if (len_a <= 3 || stack_a_sorted(x->a))
		return ;
	if (len_a > 3 && !stack_a_sorted(x->a))
	{
		push = divide_a(x, len_a);
	}
	sort_a(x, len_a - push, len_b + push, push);
	if (len_a - push <= 3)
		sort_b(x, len_a, len_b, 0);
	else
		sort_b(x, len_a - push, len_b + push, 0);
	if (len_b == 0)
		while (push-- > 0)
			add_op_new(x, "pa");
}

void	quicksort(t_stack **a, t_stack **b, t_op **op, int len)
{
	t_all		*all;

//	print_stack_a_b(*a, *b); // test
	all = (t_all *)malloc(sizeof(t_all));
	all->a = *a;
	all->b = *b;
	all->op = *op;
//	all->len_a = len;
//	all->len_b = 0;
//	add_op(&(all->op), "sa", &(all->a), &(all->b)); // test
//	add_op_new(all, "rrr"); // test
	sort_a(all, len, 0, 0);
	*a = all->a;
	*b = all->b;
	*op = all->op;
//	free(ar);

}

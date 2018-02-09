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
#define CURRNUMB x->b->num

int		divide_b(t_all *x, int len)
{
	int		med;
	int		pa;
	int		rb;

	pa = 0;
	rb = 0;
	med = get_median(x->b, len);
	while (pa < (len / 2 + len % 2))
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
	if (len != x->len_b)
		while (rb--)
			add_op_new(x, "rrb");
	return (pa);
}

int		divide_a(t_all *x, int len)
{
	int		med;
	int		pb;
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
	if (len != x->len_a)
		while (ra--)
			add_op_new(x, "rra");
	return (pb);
}

void	sort_b(t_all *x, int len_b, int push)
{
	if (x->b && stack_b_sorted(x->b))
	{
		x->len_a += len_b;
		x->len_b -= len_b;
		while (len_b-- > 0)
			add_op_new(x, "pa");
		return ;
	}
	else if (x->b && len_b <= 3)
	{
		(x->len_b <= 3) ? sort_three_b(x, len_b) : sort_short_b(x, len_b);
		x->len_a += len_b;
		x->len_b -= len_b;
	}
	else if (len_b > 3 && !stack_b_sorted(x->b))
	{
		push = divide_b(x, len_b);
		x->len_a += push;
		x->len_b -= push;
		sort_a(x, push, 0);
		sort_b(x, len_b - push, push);
	}
}

void	sort_a(t_all *x, int len_a, int push)
{
	if (stack_a_sorted(x->a))
		return ;
	if (len_a <= 3)
	{
		if (len_a == x->len_a)
			sort_three_max(&x->a, len_a, &x->op);
		else
			sort_short_a(x, len_a);
	}
	else if (len_a > 3 && !stack_a_sorted(x->a))
	{
		push = divide_a(x, len_a);
		x->len_a -= push;
		x->len_b += push;
		sort_a(x, len_a - push, push);
		sort_b(x, push, 0);
	}
}

void	quicksort(t_stack **a, t_op **op, int length)
{
	t_all		*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->a = *a;
	all->b = NULL;
	all->op = *op;
	all->len_a = length;
	all->len_b = 0;
	sort_a(all, length, 0);
	*op = all->op;
	*a = all->a;
	optimize_op(*op);
	free(all);
}

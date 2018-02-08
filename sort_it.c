/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:05:40 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/09 16:06:18 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#define CURRNUM (*a)->num
#define NEXTNUM (*a)->next->num
#define THIRDNUM (*a)->next->next->num
#define THIRD (*a)->next->next

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

void	sort_three_max(t_stack **a, int len_a, t_op **op)
{
	while (len_a > 1)
	{
		if (CURRNUM > NEXTNUM)
		{
			if (THIRD && CURRNUM > THIRDNUM)
                add_op(op, "ra", a, NULL);
			else
				add_op(op, "sa", a, NULL);
		}
		else if (THIRD && THIRDNUM < NEXTNUM)
		{
			add_op(op, "rra", a, NULL);
		}
		len_a--;
	}
}

void	sort_reverse_stack(t_stack **a, t_stack *b, t_op **op)
{
	add_op(op, "pb", a, &b);
	while (THIRD)
	{
		add_op(op, "pb", a, &b);
		add_op(op, "rb", a, &b);
	}
	add_op(op, "sa", a, NULL);
	while (b)
		add_op(op, "pa", a, &b);
	add_op(op, "rra", a, NULL);
	add_op(op, "rra", a, NULL);
}

t_op	*sort_it(t_stack **a, int length, int wrong)
{
	t_stack		*b;
	t_op		*op;
	t_all		*all;

	b = NULL;
	op = NULL;
	if (length <= 3)
		sort_three_max(a, length, &op);
	else if (length > 3 && (wrong == length - 1))
		sort_reverse_stack(a, b, &op);
	else
    {
		all = (t_all *)malloc(sizeof(t_all));
		all->a = *a;
		all->b = b;
		all->op = op;
		all->len_a = length;
		all->len_b = 0;
		sort_a(all, length, 0);
		op = all->op;
		*a = all->a;
		optimize_op(op);
		// free(all);
	}
	return (op);
}

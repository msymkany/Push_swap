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

void	merge_stacks(t_stack **a, t_stack **b, t_op **op)
{
	int		last_a;

	last_a = get_last_num(*a);
	if (((*b) && (*a)->num > (*b)->num) && ((*b)->num > last_a ||
											last_a > (*a)->num))
	{
		add_op(op, "pa", a, b);
	}
	else if ((*b) && ((*b)->num > last_a && last_a > (*a)->num))
		add_op(op, "pa", a, b);
	else
		add_op(op, "rra", a, NULL);
}

void	sort_almost_reverse_stack(t_stack **a, t_stack *b, t_op **op)
{
	while (THIRD)
	{
		if (CURRNUM < NEXTNUM || !b)
			add_op(op, "pb", a, &b);
		else
		{
			add_op(op, "pb", a, &b);
			add_op(op, "rb", a, &b);
		}
	}
	if (CURRNUM > NEXTNUM)
		add_op(op, "sa", a, NULL);
	while (b->next && b->num > b->next->num)
		add_op(op, "pa", a, &b);
	while (b)
		merge_stacks(a, &b, op);
	while (get_last_num(*a) < CURRNUM)
	{
		add_op(op, "rra", a, NULL);
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

	b = NULL;
	op = NULL;
	if (length <= 3)
		sort_three_max(a, length, &op);
	else if (length > 5 && (wrong == length - 1))
		sort_reverse_stack(a, b, &op);
	else if (length > 5 && (wrong > length - 1 - length / 5))
		sort_almost_reverse_stack(a, b, &op);
	else
		quicksort(a, &op, length);
	return (op);
}

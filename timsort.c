/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:38:33 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/10 14:38:51 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		get_last_num(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st->num);
}

int		count_misplaced(t_stack *a)
{
	int		wrong;

	wrong = 0;
	while (a->next)
	{
		if (a->num > a->next->num)
			wrong++;
		a = a->next;
	}
	return (wrong);
}

void	divide(t_stack **a, t_stack **b, int wrong, t_op **op)
{
	while (wrong)
	{
		if ((*a)->num > (*a)->next->num)
			wrong--;
		add_op(op, "pb", a, b);
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

void	timsort(t_stack *a, int wrong, t_op **op)
{
	t_stack		*b;

	b = NULL;
	while (wrong)
	{
		wrong = (wrong % 2) ? wrong / 2 + 1 : wrong / 2;
		divide(&a, &b, wrong, op);
		while (b)
		{
			merge_stacks(&a, &b, op);
		}
		while (get_last_num(a) < a->num)
		{
			add_op(op, "rra", &a, NULL);
		}
		wrong = count_misplaced(a);
	}
}

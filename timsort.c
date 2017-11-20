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

void	divide(t_stack **a, t_stack **b, int wrong, char debug)
{
	while (wrong)
	{
		if ((*a)->num > (*a)->next->num)
			wrong--;
		pb(a, b, 1, debug);
	}
}

void	merge_stacks(t_stack **a, t_stack **b, char debug)
{
	int		last_a;

	last_a = get_last_num(*a);
	if (((*b) && (*a)->num > (*b)->num) && ((*b)->num > last_a ||
		last_a > (*a)->num))
	{
		pa(b, a, 1, debug);
	}
	else if ((*b) && ((*b)->num > last_a && last_a > (*a)->num))
		pa(b, a, 1, debug);
	else
		rra(a, b, 1, debug);
}

void	timsort(t_stack *a, int wrong, char debug)
{
	t_stack		*b;

	b = NULL;
	while (wrong)
	{
		wrong = (wrong % 2) ? wrong / 2 + 1 : wrong / 2;
		divide(&a, &b, wrong, debug);
		while (b)
		{
			merge_stacks(&a, &b, debug);
		}
		while (get_last_num(a) < a->num)
		{
			rra(&a, &b, 1, debug);
		}
		wrong = count_misplaced(a);
	}
}

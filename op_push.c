/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:49:57 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/27 16:50:00 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push(t_stack **frst, t_stack **scnd)
{
	t_stack		*st;

	st = *frst;
	if (*frst)
	{
		*frst = (*frst)->next;
		st->next = *scnd;
		*scnd = st;
	}
}

void	pa(t_stack **b, t_stack **a, char print, char debug)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

void	pb(t_stack **a, t_stack **b, char print, char debug)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

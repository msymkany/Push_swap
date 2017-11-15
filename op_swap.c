/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:49:42 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/27 16:49:47 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_stack **s)
{
	int		n;

	if (*s && (*s)->next)
	{
		n = (*s)->num;
		(*s)->num = (*s)->next->num;
		(*s)->next->num = n;
	}
}

void	sa(t_stack **a, t_stack **b, char print, char debug)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

void	sb(t_stack **a, t_stack **b, char print, char debug)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

void	ss(t_stack **a, t_stack **b, char print, char debug)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

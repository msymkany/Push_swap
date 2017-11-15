/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:50:49 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/27 16:50:56 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	reverse(t_stack **s)
{
	t_stack		*last_el;
	t_stack		*ptr;

	ptr = *s;
	if (*s && (*s)->next)
	{
		while (ptr->next->next)
			ptr = ptr->next;
		last_el = ptr->next;
		ptr->next = NULL;
		last_el->next = *s;
		*s = last_el;
	}
}

void	rra(t_stack **a, t_stack **b, char print, char debug)
{
	reverse(a);
	if (print)
		write(1, "rra\n", 4);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

void	rrb(t_stack **a, t_stack **b, char print, char debug)
{
	reverse(b);
	if (print)
		write(1, "rrb\n", 4);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

void	rrr(t_stack **a, t_stack **b, char print, char debug)
{
	reverse(a);
	reverse(b);
	if (print)
		write(1, "rrr\n", 4);
	if (debug)
	{
		if (read(0, NULL, 1))
			print_stack_a_b(*a, *b);
	}
}

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

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}

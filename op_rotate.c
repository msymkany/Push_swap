/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:50:14 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/27 16:50:26 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate(t_stack **s)
{
	t_stack		*frst_el;
	t_stack		*ptr;

	frst_el = *s;
	ptr = *s;
	if (*s && (*s)->next)
	{
		*s = (*s)->next;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = frst_el;
		frst_el->next = NULL;
	}
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

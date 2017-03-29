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

void	rra(t_stack **a)
{
	reverse(a);
}

void	rrb(t_stack **b)
{
	reverse(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
}

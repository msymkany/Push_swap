/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:46:40 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/09 16:46:45 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		all_sorted(t_stack *a, t_stack *b)
{
	if (b || !stack_a_sorted(a))
		return (0);
	return (1);
}

int		stack_a_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int		stack_b_sorted(t_stack *b)
{
	while (b->next)
	{
		if (b->num < b->next->num)
			return (0);
		b = b->next;
	}
	return (1);
}

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

void	commands(char *com, t_stack **a, t_stack **b)
{
	if (ft_strequ(com, "sa"))
		sa(a);
	else if (ft_strequ(com, "sb"))
		sb(b);
	else if (ft_strequ(com, "ss"))
		ss(a, b);
	else if (ft_strequ(com, "pa"))
		pa(a, b);
	else if (ft_strequ(com, "pb"))
		pb(a, b);
	else if (ft_strequ(com, "ra"))
		ra(a);
	else if (ft_strequ(com, "rb"))
		rb(b);
	else if (ft_strequ(com, "rr"))
		rr(a, b);
	else if (ft_strequ(com, "rra"))
		rra(a);
	else if (ft_strequ(com, "rrb"))
		rrb(b);
	else if (ft_strequ(com, "rrr"))
		rrr(a, b);
	else
		ft_error();
}

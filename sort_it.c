/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:05:40 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/09 16:06:18 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		get_min(t_stack *a)
{
	int		min;

	min = a->num;
	while (a->next)
	{
		a = a->next;
		if (a->num < min)
			min = a->num;
	}
	return (min);
}

void	bubble_sort(t_stack *a, char debug)
{
	int			min;
	t_stack		*b;

	b = NULL;
	min = get_min(a);
	while (count_misplaced(a))
	{
		if (a->next->num != min && a->num > a->next->num)
			sa(&a, &b, 1, debug);
		else
			ra(&a, &b, 1, debug);
	}
}

int		get_pre_last(t_stack *a)
{
	while (a->next->next)
		a = a->next;
	return (a->num);
}

void	sort_reverse_stack(t_stack *a, char debug)
{
	t_stack		*b;
	int			pre_last;

	b = NULL;
	pb(&a, &b, 1, debug);
	pre_last = get_pre_last(a);
	while (a->num != pre_last)
	{
		pb(&a, &b, 1, debug);
		rb(&a, &b, 1, debug);
	}
	sa(&a, &b, 1, debug);
	while (b)
		pa(&b, &a, 1, debug);
	rra(&a, &b, 1, debug);
	rra(&a, &b, 1, debug);
}

void	sort_it(t_stack *a, int length, int wrong, char debug)
{
	wrong = count_misplaced(a);
	if (length > 3 && (wrong == length - 1))
		sort_reverse_stack(a, debug);
	else if (length < 6)
		bubble_sort(a, debug);
	else
		timsort(a, wrong, debug);
}

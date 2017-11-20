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

//int		get_min(t_stack *a)
//{
//	int		min;
//
//	min = a->num;
//	while (a->next)
//	{
//		a = a->next;
//		if (a->num < min)
//			min = a->num;
//	}
//	return (min);
//}
//
//void	bubble_sort(t_stack *a, char debug)
//{
//	int			min;
//	t_stack		*b;
//
//	b = NULL;
//	min = get_min(a);
//	while (count_misplaced(a))
//	{
//		if (a->next->num != min && a->num > a->next->num)
//			sa(&a, &b, 1, debug);
//		else
//			ra(&a, &b, 1, debug);
//	}
//}

//int		get_pre_last(t_stack *a)
//{
//	while (a->next->next)
//		a = a->next;
//	return (a->num);
//}

void	sort_three_max(t_stack *a, t_stack *b, int len_a, char debug)
{
	while (len_a > 1)
	{
		if (a->num > a->next->num)
		{
			if (a->next->next && a->num > a->next->next->num)
				ra(&a, &b, 1, debug);
			else
			{
				sa(&a, &b, 1, debug);
			}
		}
		else if (a->next->next && a->next->next->num < a->next->num)
			rra(&a, &b, 1, debug);
		len_a--;
	}
}

void	sort_almost_reverse_stack(t_stack *a, t_stack *b, char debug)
{
	while (a->next->next)
	{
		if (a->num < a->next->num || !b)
			pb(&a, &b, 1, debug);
		else
		{
			pb(&a, &b, 1, debug);
			rb(&a, &b, 1, debug);
		}
	}
	if (a->num > a->next->num)
		sa(&a, &b, 1, debug);
	while (b->next && b->num > b->next->num)
		pa(&b, &a, 1, debug);
	while (b)
		merge_stacks(&a, &b, debug);
	while (get_last_num(a) < a->num)
	{
		rra(&a, &b, 1, debug);
	}
}

void	sort_reverse_stack(t_stack *a, t_stack *b, char debug)
{
	pb(&a, &b, 1, debug);
	while (a->next->next)
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
	t_stack		*b;

	b = NULL;
	wrong = count_misplaced(a);
	if (length <= 3)
		sort_three_max(a, b, length, debug);
	else if (length > 3 && (wrong == length - 1))
		sort_reverse_stack(a, b, debug);
	else if (wrong >= length - 1 - length / 10)
//	else if (length > 10 && (wrong >= length - 1 - length / 10))
		sort_almost_reverse_stack(a, b, debug);
	else
		quicksort(a, b, wrong, debug);
}

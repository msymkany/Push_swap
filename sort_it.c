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
//			add_op(op, "sa");
//		else
//			add_op(op, "ra");
//	}
//}

//int		get_pre_last(t_stack *a)
//{
//	while (a->next->next)
//		a = a->next;
//	return (a->num);
//}

void	sort_three_max(t_stack *a, t_stack *b, int len_a, t_op *op)
{
	while (len_a > 1)
	{
		if (a->num > a->next->num)
		{
			if (a->next->next && a->num > a->next->next->num)
				add_op(op, "ra");
			else
			{
				add_op(op, "sa");
			}
		}
		else if (a->next->next && a->next->next->num < a->next->num)
			add_op(op, "rra");
		len_a--;
	}
}

void	sort_almost_reverse_stack(t_stack *a, t_stack *b, t_op *op)
{
	while (a->next->next)
	{
		if (a->num < a->next->num || !b)
			add_op(op, "pb");
		else
		{
			add_op(op, "pb");
			add_op(op, "rb");
		}
	}
	if (a->num > a->next->num)
		add_op(op, "sa");
	while (b->next && b->num > b->next->num)
		add_op(op, "pa");
	while (b)
		merge_stacks(&a, &b, op);
	while (get_last_num(a) < a->num)
	{
		add_op(op, "rra");
	}
}

void	sort_reverse_stack(t_stack *a, t_stack *b, t_op *op)
{
	add_op(op, "pb");
	while (a->next->next)
	{
		add_op(op, "pb");
		add_op(op, "rb");
	}
	add_op(op, "sa");
	while (b)
		add_op(op, "pa");
	add_op(op, "rra");
	add_op(op, "rra");
}

t_op	*sort_it(t_stack *a, int length, int wrong)
{
	t_stack		*b;
	t_op		*op;

	b = NULL;
	wrong = count_misplaced(a);
	if (length <= 3)
		sort_three_max(a, b, length, op);
	else if (length > 3 && (wrong == length - 1))
		sort_reverse_stack(a, b, op);
	else if (wrong >= length - 1 - length / 10)
//	else if (length > 10 && (wrong >= length - 1 - length / 10))
		sort_almost_reverse_stack(a, b, op);
	else
		quicksort(a, b, op);
	return (op);
}

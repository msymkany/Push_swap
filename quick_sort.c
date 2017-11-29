/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:59:40 by msymkany          #+#    #+#             */
/*   Updated: 2017/11/20 15:59:44 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//int 	get_median(t_stack *a)
//{
//	int		min;
//	int 	max;
//
//	min = a->num;
//	max = a->num;
//	while (a->next)
//	{
//		a = a->next;
//		if (a->num < min)
//			min = a->num;
//		if (a->num > max)
//			max = a->num;
//	}
//	return ((max + min) / 2);
//}
//
//void	divide_a(t_stack *a, t_stack *b, char debug)
//{
//	int 	mean;
//
//	mean = get_median(a);
//	while (a->next->next)
//	{
//		if (a->num < mean)
//			pb(&a, &b, 1, debug);
//		else
//			ra(&a, &b, 1, debug);
//	}
//}

void	quicksort(t_stack *a, t_stack *b, t_op **op)
{

	print_stack_a_b(a, b);
	(void) op;
	ft_printf("quicksort here");
//	if (a->next->next && !stack_a_sorted(a))
//		divide_a(a, b, debug);
//	else if (b->next->next && !stack_b_sorted(b))
//		divide_b(a, b, debug);
//	else
//		sort_three_max(a, b, 3, debug);
}

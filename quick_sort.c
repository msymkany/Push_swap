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
#define CURRNUM (*a)->num
#define NEXTNUM (*a)->next->num
#define THIRDNUM (*a)->next->next->num
#define THIRD (*a)->next->next
#define THIRDB (*b)->next->next

//int 	get_median(t_stack *a)
//{
//
//}

int 	get_mean(t_stack **a, int len)
{ // get median, not mean!!!!
	int		min;
	int 	max;
	int     i;
	t_stack *ptr;

	i = 1;
	min = CURRNUM;
	max = CURRNUM;
	ptr = (*a)->next;
	while (i < len)
	{
		if (ptr->num < min)
			min = ptr->num;
		if (ptr->num > max)
			max = ptr->num;
		ptr = ptr->next;
		i++;
	}
	return ((max + min) / 2);
}

int     divide_b(t_stack **a, t_stack **b, t_op **op, int len)
{
	int 	mean;
	int     i;
	int     pa;

	i = 0;
	pa = 0;
	mean = get_mean(b, len);
	while (i < len)
	{
		if (CURRNUM > mean)
		{
            add_op(op, "pa", a, b);
			pa++;
		}
		else
			add_op(op, "rb", a, b);
		i++;
	}
	len = len - pa;
	while (len--)
	{
		add_op(op, "rrb", a, b);
	}
	return (pa);
}

int     divide_a(t_stack **a, t_stack **b, t_op **op, int len)
{
	int 	mean;
	int     i;
	int     pb;

	i = 0;
	pb = 0;
	mean = get_mean(a, len);
	while (i < len)
	{
		if (CURRNUM < mean)
		{
			add_op(op, "pb", a, b);
			pb++;
		}
		else
			add_op(op, "ra", a, b);
		i++;
	}
	len = len - pb;
	while (len--)
	{
		add_op(op, "rra", a, b);
	}
	return (pb);
}

/*
** pushed - numbers that was pushed to second stack
*/

void	quicksort(t_stack **a, t_stack **b, t_op **op, int len, char stack)
{
	int     pushed;

	pushed = len;
//	print_stack_a_b(*a, *b); // test
//	(void) op;
//	ft_printf("quicksort here"); // test
	if (len > 3)
	{
		if (THIRD && !stack_a_sorted(*a))
		{
			pushed = divide_a(a, b, op, pushed);
			quicksort(a, b, op, pushed, 'a');
		}
		else if (THIRDB && !stack_b_sorted(*b))
		{
			pushed = divide_b(a, b, op, pushed);
			quicksort(a, b, op, pushed, 'b');
		}
	}
	else
	{
//		ft_printf("sort_three_max()");
		while (len--)
			(stack == 'a') ? add_op(op, "pa", a, b) : add_op(op, "pb", a, b);
	}
}

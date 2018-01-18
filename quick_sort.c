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
#define CURRNUMB (*b)->num
#define NEXTNUMB (*b)->next->num
#define THIRDB (*b)->next->next

int		partition(int *arr, int left, int right)
{
	int 	j;
	int 	i;
	int		num;
	int		swap;

	i = left - 1;
	j = left;
	num = arr[right];
	while (j <= right - 1)
	{
		if (arr[j] <= num)
		{
			i++;
			swap = arr[j];
			arr[j] = arr[i];
			arr[i] = swap;
		}
		j++;
	}
	swap = arr[i + 1];
	arr[i + 1] = arr[right];
	arr[right] = swap;
	return (i + 1);
}

int		quickmedian(int *arr, int left, int right, int med)
{
	int 	part;

	part = partition(arr, left, right);
	if (part == med)
		return (arr[part]);
	else if (part < med)
		return (quickmedian(arr, part + 1, right, med));
	else
		return (quickmedian(arr, left, part - 1, med));
}

int 	get_median(t_stack *a, int len)
{
	int 	arr[len];
	int		i;
	int 	med;

	i = 0;
	while (i < len)
	{
		arr[i] = a->num;
		a = a->next;
		i++;
	}
	med = ((len / 2) % 2 == 0) ? (len / 2) : (len / 2 + 1);
	return (quickmedian(arr, 0, len - 1, med));
}

void	sort_short(t_stack **a, t_stack **b, t_op **op, int *len)
{
	if (CURRNUM > NEXTNUM)
		add_op(op, "sa", a, b);
	if ((*b) && CURRNUMB < NEXTNUMB)
		add_op(op, "sb", a, b);
	if (len[0] == 3)
		add_op(op, "ra", a, b);
	if (len[1] == 3)
		add_op(op, "rb", a, b);
	if (CURRNUM > NEXTNUM)
		add_op(op, "sa", a, b);
	if ((*b) && CURRNUMB < NEXTNUMB)
		add_op(op, "sb", a, b);
	if (len[0] == 3)
		add_op(op, "rra", a, b);
	if (len[1] == 3)
		add_op(op, "rrb", a, b);
	if (CURRNUM > NEXTNUM)
		add_op(op, "sa", a, b);
	if ((*b) && CURRNUMB < NEXTNUMB)
		add_op(op, "sb", a, b);
}

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
//	mean = get_mean(b, len);
	mean = get_median(*a, len);
	while (i < len)
	{
		if (CURRNUMB > mean)
		{
			add_op(op, "pa", a, b);
			pa++;
		}
		else
			add_op(op, "rb", a, b);
		i++;
	}
	len = len - pa;
//	while (len--)
//	{
//		add_op(op, "rrb", a, b);
//	}
	return (pa);
}

int     divide_a(t_stack **a, t_stack **b, t_op **op, int len)
{
	int 	mean;
	int     i;
	int     pb;

	i = 0;
	pb = 0;
//	mean = get_mean(a, len);
	mean = get_median(*a, len);
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
//	while (len--)
//	{
//		add_op(op, "rra", a, b);
//	}
	return (pb);
}

/*
** pushed - numbers that was pushed to second stack
*/

void	quicksort(t_stack **a, t_stack **b, t_op **op, int *len, char stack)
{
	int     i;

	if ((stack == 'a' && len[0] > 3) || (stack == 'b' && len[1] > 3))
	{
		if (THIRD && !stack_a_sorted(*a))
		{
			len[1] = divide_a(a, b, op, len[0]);
			len[0] -= len[1];
			quicksort(a, b, op, len, 'a');
//			quicksort(a, b, op, len, 'b');
		}
		if (*b && (*b)->next && THIRDB && !stack_b_sorted(*b))
		{
			len[0] = divide_b(a, b, op, len[1]);
			len[1] -= len[0];
			quicksort(a, b, op, len, 'b');
//			quicksort(a, b, op, len, 'a');
		}
	}
	else
	{
		i = 0;
		sort_short(a, b, op, len);
		if (stack == 'a')
		{
			while (i++ < (len[0]))
				add_op(op, "pa", a, b);
//			quicksort(a, b, op, len, 'b');
		}
		else
		{
			while (i++ < (len[1]))
				add_op(op, "pa", a, b);
//			quicksort(a, b, op, len, 'a');
		}
	}
}

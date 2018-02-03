/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 20:35:53 by msymkany          #+#    #+#             */
/*   Updated: 2018/01/25 20:35:56 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
	med = (len % 2 == 0) ? (len / 2) : (len / 2);
	return (quickmedian(arr, 0, len - 1, med));
}

//int 	get_mean(t_stack **a, int len)
//{
//	int		min;
//	int 	max;
//	int     i;
//	t_stack *ptr;
//
//	i = 1;
//	min = CURRNUM;
//	max = CURRNUM;
//	ptr = (*a)->next;
//	while (i < len)
//	{
//		if (ptr->num < min)
//			min = ptr->num;
//		if (ptr->num > max)
//			max = ptr->num;
//		ptr = ptr->next;
//		i++;
//	}
//	return ((max + min) / 2);
//}
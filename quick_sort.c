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
#define CURRNUM x->a->num
#define CURRNUMB x->b->num

int		divide_b(t_all *x, int len)
{
	int		med;
	int		pa;
	int		rb;

	pa = 0;
	rb = 0;
	med = get_median(x->b, len);
	while (pa < (len / 2 + len % 2))
	{
		if (CURRNUMB >= med)
		{
			add_op_new(x, "pa");
			pa++;
		}
		else
		{
			add_op_new(x, "rb");
			rb++;
		}
	}
	if (len != x->len_b)
		while (rb--)
			add_op_new(x, "rrb");
	return (pa);
}

int		divide_a(t_all *x, int len)
{
	int		med;
	int		pb;
	int		ra;

	pb = 0;
	ra = 0;
	med = get_median(x->a, len);
	while (pb < len / 2)
	{
		if (CURRNUM < med)
		{
			add_op_new(x, "pb");
			pb++;
		}
		else
		{
			add_op_new(x, "ra");
			ra++;
		}
	}
	if (len != x->len_a)
		while (ra--)
			add_op_new(x, "rra");
	return (pb);
}

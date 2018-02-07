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
#define NEXTNUM x->a->next->num
#define CURRNUMB x->b->num
#define NEXTNUMB x->b->next->num
#define THIRDB x->b->next->next
#define THIRDNUMB x->b->next->next->num

void	sort_three_b(t_all *x, int len_b)
{
	int 	j;

	j = len_b;
	while (len_b > 1)
	{
		if (CURRNUMB < NEXTNUMB)
		{
			if (THIRDB && CURRNUMB < THIRDNUMB)
				add_op_new(x, "rb");
			else
				add_op_new(x, "sb");
		}
		else if (THIRDB && THIRDNUMB > NEXTNUMB)
		{
			add_op_new(x, "rrb");
		}
		len_b--;
	}
	while (j-- > 0)
		add_op_new(x, "pa");
}

void	sort_short_b(t_all *x, int len_b)
{
	if (len_b == 3 && CURRNUMB > NEXTNUMB && CURRNUMB > THIRDNUMB)
	{
		add_op_new(x, "pa");
		len_b--;
	}
	if (CURRNUMB < NEXTNUMB)
		if (len_b == 2 || (len_b == 3 && NEXTNUMB > THIRDNUMB))
		{
			add_op_new(x, "sb");
			add_op_new(x, "pa");
			len_b--;
			if (len_b == 2 && CURRNUMB < NEXTNUMB)
				add_op_new(x, "sb");
		}
	if (len_b == 3)
	{
		add_op_new(x, "rb");
		add_op_new(x, "sb");
		add_op_new(x, "pa");
		len_b--;
		if (get_last_num(x->b) < CURRNUMB)
		{
			add_op_new(x, "pa");
			len_b--;
		}
		add_op_new(x, "rrb");
	}
	while (len_b-- > 0)
		add_op_new(x, "pa");
}

void	sort_short_a(t_all *x, int len_a)
{
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (len_a == 3)
		add_op_new(x, "ra");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (len_a == 3)
		add_op_new(x, "rra");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
}

int     divide_b(t_all *x, int len)
{
	int 	med;
	int     pa;
	int		rb;
	int 	i;

	pa = 0;
	rb = 0;
	i = len / 2 + len % 2;
	med = get_median(x->b, len);
	while (pa < i)
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

int     divide_a(t_all *x, int len)
{
	int 	med;
	int     pb;
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

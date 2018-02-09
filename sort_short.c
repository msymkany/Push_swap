/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:06:46 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/08 21:06:48 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#define CURRNUM x->a->num
#define NEXTNUM x->a->next->num
#define THIRDNUM x->a->next->next->num
#define CURRNUMB x->b->num
#define NEXTNUMB x->b->next->num
#define THIRDB x->b->next->next
#define THIRDNUMB x->b->next->next->num

void	sort_three_b(t_all *x, int len_b)
{
	int		j;

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

int		sort_short_b_2(t_all *x, int len_b)
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
	return (len_b);
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
		len_b = sort_short_b_2(x, len_b);
	while (len_b-- > 0)
		add_op_new(x, "pa");
}

void	sort_short_a(t_all *x, int len_a)
{
	if (CURRNUM > NEXTNUM && THIRDNUM > CURRNUM)
	{
		add_op_new(x, "sa");
		return ;
	}
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

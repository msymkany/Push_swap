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
#define THIRDNUM x->a->next->next->num
#define THIRD x->a->next->next
#define CURRNUMB x->b->num
#define NEXTNUMB x->b->next->num
#define ALEN x->len_a
#define BLEN x->len_b

void	sort_short_b(t_all *x, int len_b)
{
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (len_b == 3)
		add_op_new(x, "rb");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (len_b == 3) //here
		add_op_new(x, "rrb");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
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

void	sort_b(t_all *x, int len_b, int push)
{
	if (x->b && stack_b_sorted(x->b))
	{
		x->len_a += len_b;
		x->len_b -= len_b;
		while (len_b-- > 0)
			add_op_new(x, "pa");
		return ;
	}
	else if (len_b <= 3)
	{
		sort_short_b(x, len_b);
		x->len_a += len_b;
		x->len_b -= len_b;
		while (len_b-- > 0)
			add_op_new(x, "pa");
	}
	else if (len_b > 3 && !stack_b_sorted(x->b))
	{
		push = divide_b(x, len_b);
		x->len_a += push;
		x->len_b -= push;
		sort_a(x, push, 0);
		sort_b(x, len_b - push, push);
	}
}

void	sort_a(t_all *x, int len_a, int push)
{
//	add_op(&(x->op), "sa", &(x->a), &(x->b)); // test
//	add_op_new(x, "rrr"); // test
	if (stack_a_sorted(x->a))
		return ;
	if (len_a <= 3)
		sort_short_a(x, len_a);
	else if (len_a > 3 && !stack_a_sorted(x->a))
	{
		push = divide_a(x, len_a);
		x->len_a -= push;
		x->len_b += push;
		sort_a(x, len_a - push, push);
		sort_b(x, push, 0);
	}
}

void	quicksort(t_stack **a, t_stack **b, t_op **op, int len)
{
	t_all		*all;

//	print_stack_a_b(*a, *b); // test
	all = (t_all *)malloc(sizeof(t_all));
	all->a = *a;
	all->b = *b;
	all->op = *op;
	all->len_a = len;
	all->len_b = 0;
//	add_op(&(all->op), "sa", &(all->a), &(all->b)); // test
//	add_op_new(all, "rrr"); // test
	sort_a(all, len, 0);
	*a = all->a;
	*b = all->b;
	*op = all->op;
//	free(ar);

}

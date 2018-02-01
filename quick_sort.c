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

void	sort_short(t_all *x)
{
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (ALEN == 3)
		add_op_new(x, "ra");
	if (BLEN == 3)
		add_op_new(x, "rrb");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (ALEN == 3)
		add_op_new(x, "rra");
	if (BLEN == 3)
		add_op_new(x, "rrb");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if (x->b && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");

}

int     divide_b(t_all *x, int len)
{
	int 	med;
	int     pa;
	int		rb;

	pa = 0;
	rb = 0;
	med = get_median(x->b, len);
	while (pa < len / 2)
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
	//reflect, what was pushed
	sort_a(x, 0);
	// sort_a();
	if (rb && rb < (pa - rb))
		while (rb--)
			add_op_new(x, "rrb");
	else
		while (rb++ <= pa)
			add_op_new(x, "rb");
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
	if (ra && ra < (pb - ra))
		while (ra--)
			add_op_new(x, "rra");
	else
		while (ra++ <= pb)
			add_op_new(x, "ra");
	return (pb);
}

void	sort_b(t_all *x, int pa)
{
	//stack len needs to adjust
	if (BLEN <= 3)
	{
		sort_short(x);
		while (pa-- > 0)
		{
			add_op_new(x, "pb");
		}
	}
	if  (BLEN <= 3 || stack_b_sorted(x->b))
		return ;
	sort_a(x, 0);
	if (BLEN > 3 && !stack_b_sorted(x->b))
	{
		pa = divide_b(x, BLEN - pa);
	}
	sort_b(x, pa);
}

void	sort_a(t_all *x, int pb)
{
//	add_op(&(x->op), "sa", &(x->a), &(x->b)); // test
//	add_op_new(x, "rrr"); // test
	if (x->len_a <= 3)
	{
		sort_short(x);
		while (pb-- > 0)
		{
			add_op_new(x, "pa");
		}
	}
	if (ALEN <= 3 || stack_a_sorted(x->a))
		return ;
	if (ALEN > 3 && !stack_a_sorted(x->a))
	{
		pb = divide_a(x, ALEN - pb);
	}
	sort_a(x, pb);
	sort_b(x, 0);
}

void	quicksort(t_stack **a, t_stack **b, t_op **op, int len)
{
	t_all		*all;

	print_stack_a_b(*a, *b); // test
	all = (t_all *)malloc(sizeof(t_all));
	all->a = *a;
	all->b = *b;
	all->op = *op;
	all->len_a = len;
	all->len_b = 0;
//	add_op(&(all->op), "sa", &(all->a), &(all->b)); // test
//	add_op_new(all, "rrr"); // test
	sort_a(all, 0);
	*a = all->a;
	*b = all->b;
	*op = all->op;
//	free(ar);

}

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
//#define CURRNUM (*a)->num
//#define NEXTNUM (*a)->next->num
//#define THIRDNUM (*a)->next->next->num
//#define THIRD (*a)->next->next
//#define CURRNUMB (*b)->num
//#define NEXTNUMB (*b)->next->num
//#define THIRDB (*b)->next->next

#define CURRNUM x->a->num
#define NEXTNUM x->a->next->num
#define THIRDNUM x->a->next->next->num
#define THIRD x->a->next->next
#define CURRNUMB x->b->num
#define NEXTNUMB x->b->next->num

void	sort_short(t_all x)
{
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if ((*b) && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (len[0] == 3)
		add_op(&(x->op), "ra", a, b);
	if (len[1] == 3)
		add_op_new(x, "rrb");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if ((*b) && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");
	if (len[0] == 3)
		add_op(&(x->op), "rra", a, b);
	if (len[1] == 3)
		add_op_new(x, "rrb");
	if (CURRNUM > NEXTNUM)
		add_op_new(x, "sa");
	if ((*b) && CURRNUMB < NEXTNUMB)
		add_op_new(x, "sb");

}

//int     divide_b(t_stack **a, t_stack **b, t_op **op, int *len) // old
//{
//	int 	med;
//	int     pa;
//	int		rb;
//
//	pa = 0;
//	rb = 0;
//	med = get_median(*b, len[1]);
//	while (pa < len[1] / 2)
//	{
//		if (CURRNUMB >= med)
//		{
//			add_op(op, "pa", a, b);
//			pa++;
//		}
//		else
//		{
//			add_op(op, "rb", a, b);
//			rb++;
//		}
//	}
//	sort_a(a, b, op, len);
//	// sort_a();
//	if (rb && rb < (pa - rb))
//		while (rb--)
//			add_op(op, "rrb", a, b);
//	else
//		while (rb++ <= pa)
//			add_op(op, "rb", a, b);
//	return (pa);
//}
//
//int     divide_a(t_stack **a, t_stack **b, t_op **op, int len)
//{
//	int 	med;
//	int     pb;
//	int		ra;
//
//	pb = 0;
//	ra = 0;
//	med = get_median(*a, len);
//	while (pb < len / 2)
//	{
//		if (CURRNUM < med)
//		{
//			add_op(op, "pb", a, b);
//			pb++;
//		}
//		else
//		{
//			add_op(op, "ra", a, b);
//			ra++;
//		}
//	}
//	if (ra && ra < (pb - ra))
//		while (ra--)
//			add_op(op, "rra", a, b);
//	else
//		while (ra++ <= pb)
//			add_op(op, "ra", a, b);
//	return (pb);
//}
//
///*
//** pushed - numbers that was pushed to second stack
//*/
//
//void	sort_b(t_stack **a, t_stack **b, t_op **op, int *len)
//{
////	int i;
//	len[1] -= len[2];
//	len[0] += len[2];
//	len[3] = 0;
//	if (len[1] <= 3)
//	{
//		sort_short(a, b, op, len);
//		while (len[2]-- > 0)
//		{
//			add_op(op, "pb", a, b);
//		}
//		len[2] = 0;
//	}
//	if  (len[1] <= 3 || stack_b_sorted(*b))
//		return ;
//	sort_a(a, b, op, len);
//	if (len[1] > 3 && !stack_b_sorted(*b))
//	{
//		len[2] = divide_b(a, b, op, len);
////		len[1] -= len[0];
//	}
//	sort_b(a, b, op, len);
//
//
//}
//
void	sort_a(t_all *x, int *pa)
{
//	add_op(&(x->op), "sa", &(x->a), &(x->b)); // test
//	add_op_new(x, "rrr"); // test
	if (x->len_a <= 3)
	{
		sort_short(x);
		while (len[3]-- > 0)
		{
			add_op(op, "pa", a, b);
			len[2]++;
		}
		len[3] = 0;
	}
	if (len[0] <= 3 || stack_a_sorted(*a))
		return ;
	if (len[0] > 3 && !stack_a_sorted(*a))
	{
		len[3] = divide_a(a, b, op, len[0]);
	}
	sort_a(a, b, op, len);
	sort_b(a, b, op, len);


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

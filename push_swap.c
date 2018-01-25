/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:55:52 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/13 20:34:03 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		visualize(int *stack, int length, t_op *op)
{
	t_stack		*a;
	t_stack		*b;
	int 		num;

	num = 0;
	b = NULL;
	a = push_to_list(stack, length);
	while (op)
	{
		print_stack_a_b(a, b);
		read(0, NULL, 1);
		ft_printf("%s\n", op->op);
		commands(op->op, &a, &b);
		op = op->next;
		num++;
	}
	print_stack_a_b(a, b); //test
	del_stack(a);
	return (num);
}

void	sort_print(int *stack, int length, int wrong, char flag)
{
	t_stack		*list;
	t_op		*op;
	t_op		*ptr;
	int 		num;

	ptr = NULL;
	num = 0;
	list = push_to_list(stack, length);
	if (flag & 2)
		print_stack_a_b(list, NULL);
	op = sort_it(&list, length, wrong);
	if (flag & 4)
		print_stack_a_b(list, NULL);
	if (flag & 1)
		num = visualize(stack, length, op);
	else
	{
		ptr = op;
		while (ptr)
		{
			ft_printf("%s\n", ptr->op);
			ptr = ptr->next;
			num++;
		}
	}
	if (flag & 8)
		ft_printf("Number of operations: %d\n", num);
	del_stack(list);
	del_op(op);
}


int		main(int ar, char **av)
{
	int			*stack;
	int			wrong;
	char		flag;
	int 		count_flag;

	wrong = 0;
	flag = 0;
	count_flag = 0;
	stack = 0;
	if (ar == 1)
		ft_usage(av[0]);
	else
	{
		count_flag = get_flags(ar, av, &flag);
		stack = (read_stack(ar, av, &wrong, count_flag));
		if (wrong == 0)
		{
//			while(1); //test
			exit(0);
		}
		else
		{
			sort_print(stack, ar - count_flag, wrong,flag);
		}
	}
	free(stack);
	while (1);
	return (0);
}

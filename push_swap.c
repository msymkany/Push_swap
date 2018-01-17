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

void	visualize(int *stack, int length, t_op *op)
{
	t_stack		*a;
	t_stack		*b;
//	t_stack		*ptr;

	b = NULL;
	a = push_to_list(stack, length);
//	ptr = a;
	while (op)
	{
		ft_printf("%s\n", op->op);
		print_stack_a_b(a, b); //test
		commands(op->op, &a, &b);
//		ptr = ptr->next;
		op = op->next;

	}
	print_stack_a_b(a, b); //test
	del_stack(a);
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
	op = sort_it(&list, --length, wrong);
	if (flag & 4)
		print_stack_a_b(list, NULL);
	if (flag & 1)
		visualize(stack, length, op);
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
		ft_printf("%d\n", num);
	del_stack(list);
	del_op(op);
}

int 	get_flags(int ar, char **av, char *flag)
{
	int  i;

	i = 1;
	while (i < ar && av[i][0] == '-')
	{
		if (ft_strequ(av[1], "-v")) //visualization
			(*flag) = (*flag) | 1;
		else if (ft_strequ(av[1], "-f")) // first
			(*flag) = (*flag) | 2;
		else if (ft_strequ(av[1], "-l")) // last
			(*flag) = (*flag) | 4;
		else if (ft_strequ(av[1], "-c")) // count op
			(*flag) = (*flag) | 8;
		else
			ft_error();
		i++;
	}
	if (!av[i])
		ft_usage(av[0]);
	else if ((*flag) & 1)
		(*flag) = (*flag) & 9;
 	return (i);
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
	if (ar == 1) //|| (ar == 2 && ft_strequ(av[1], "-v")))
		ft_usage(av[0]);
	else
	{
		count_flag = get_flags(ar, av, &flag);
		stack = (read_stack(ar - count_flag, av, &wrong, count_flag));
		if (wrong == 0)
			exit(0);
		else
		{
			sort_print(stack, ar - count_flag, wrong,flag);
		}
	}
	return (0);
}

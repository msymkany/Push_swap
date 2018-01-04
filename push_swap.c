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

void	sort_print(int *stack, int length, int wrong, char debug)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*list;
	t_op		*op;
	t_op		*ptr;

	b = NULL;
	ptr = NULL;
	a = push_to_list(stack, length);
	list = push_to_list(stack, length);
	op = sort_it(&list, --length, wrong);
    print_stack_a_b(list, b); //test
	del_stack(list);
//	list = a;
	ptr = op;
	while (ptr)
	{
		if (debug)
		{
			print_stack_a_b(a, b);
		}
		ft_printf("%s\n", ptr->op);
		commands(ptr->op, &a, &b);
		ptr = ptr->next;
	}
	if (debug)
		print_stack_a_b(a, b);
	del_op(op);
	del_stack(a);
}

int		main(int ar, char **av)
{
	int			*stack;
	int			wrong;
	char		debug;

	wrong = 0;
	debug = 0;
	if (ar == 1 || (ar == 2 && ft_strequ(av[1], "-v")))
		ft_usage(av[0]);
	else
	{
		if (ft_strequ(av[1], "-v"))
			debug = 1;
		stack = (read_stack(ar, av, &wrong));
		if (wrong == 0)
		{
			exit(0);
		}
		else
		{
			sort_print(stack, ar - debug, wrong, debug);
		}
	}
	return (0);
}

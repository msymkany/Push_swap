/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:55:52 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/25 17:55:54 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void 	print_list(t_stack *list)
{
	write(1, "That's list\n", 12);
	while (list)
	{
		ft_printf("%d\n", list->num);
		list = list->next;
	}
}

void	print_stack(int *stack, int ar)
{
	while(--ar)
	{
		ft_putnbr(*stack++);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}


int		main(int ar, char **av)
{
	int 		*stack;
	int			j;
	t_stack		*list;

	j = 0;
	if (ar == 1)
		ft_usage(av[0]);
	else
	{
		stack = (read_stack(ar, av, &j));
		print_stack(stack, ar);
		if (j == 0)
		{
			write(1, "NO sort is needed\n", 18); // test
			print_stack(stack, ar);
			exit(0);
		}
		else
		{
			list = push_to_list(stack, ar);
			print_list(list); //test
	//		sort_it();
		}
	}
	return (0);
}
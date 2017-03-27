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
		if (j == 0)
		{
			write(1, "NO sort is needed\n", 18); // test
			while(--ar)
			{
				ft_putnbr(*stack++);
				write(1, " ", 1);
			}
			write(1, "\n", 1);
			exit(0);
		}
		else
		{
			list = push_to_stack(stack, ar);
			write(1, "That's list\n", 12);
			while (list)
			{
				ft_printf("%d\n", list->num);
				ft_putchar('\n');
				list = list->next;
			}
//			list = sort_it();
		}
	}
	return (0);
}
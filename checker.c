/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:56:09 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/13 20:30:37 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	checker(t_stack *a, int wrong)
{
	t_stack		*b;
	char		*line;

	b = NULL;
	while (get_next_line(0, &line))
	{
		commands(line, &a, &b);

		if (wrong == 0)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (wrong)
	{
		if (all_sorted(a, b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "OK\n", 3);
}

int		main(int ar, char **av)
{
	int			*stack;
	int			wrong;
	t_stack		*a;
	char		flag;
	int 		count_flag;

	wrong = 0;
	flag = 0;
	if (ar == 1)
		ft_usage(av[0]);
	else
	{
		count_flag = get_flags(ar, av, &flag);
		stack = (read_stack(ar, av, &wrong, count_flag));
		a = push_to_list(stack, (ar - count_flag));
		checker(a, wrong);
	}
	return (0);
}

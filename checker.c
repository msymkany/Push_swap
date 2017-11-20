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

void	commands(char *com, t_stack **a, t_stack **b, char debug)
{
	if (!(ft_strcmp(com, "sa")))
		sa(a, b, debug, debug);
	else if (!(ft_strcmp(com, "sb")))
		sb(a, b, debug, debug);
	else if (!(ft_strcmp(com, "ss")))
		ss(a, b, debug, debug);
	else if (!(ft_strcmp(com, "pa")))
		pa(b, a, debug, debug);
	else if (!(ft_strcmp(com, "pb")))
		pb(a, b, debug, debug);
	else if (!(ft_strcmp(com, "ra")))
		ra(a, b, debug, debug);
	else if (!(ft_strcmp(com, "rb")))
		rb(a, b, debug, debug);
	else if (!(ft_strcmp(com, "rr")))
		rr(a, b, debug, debug);
	else if (!(ft_strcmp(com, "rra")))
		rra(a, b, debug, debug);
	else if (!(ft_strcmp(com, "rrb")))
		rrb(a, b, debug, debug);
	else if (!(ft_strcmp(com, "rrr")))
		rrr(a, b, debug, debug);
	else
		ft_error();
}

void	checker(t_stack *a, int wrong, char debug)
{
	t_stack		*b;
	char		*line;

	b = NULL;
	while (get_next_line(0, &line))
	{
		commands(line, &a, &b, debug);
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
		a = push_to_list(stack, (ar - debug));
		checker(a, wrong, debug);
	}
	return (0);
}

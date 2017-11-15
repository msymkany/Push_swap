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

int		main(int ar, char **av)
{
	int			*stack;
	int			wrong;
	t_stack		*list;
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
			list = push_to_list(stack, (ar - debug));
			sort_it(list, --ar - debug, wrong, debug);
		}
	}
	return (0);
}

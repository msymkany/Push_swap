/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:54:01 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/22 15:54:26 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void 	arg_check(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		ft_error();
	while (*str)
	{
		if (*str > '9' || *str < '0')
			ft_error();
		str++;
	}
}

int		dub_check(int *arr, int num, size_t i)
{
	int 	j;

	j = 0;
	while (i--)
	{
		if (*arr == num)
			ft_error();
		if (*arr++ > num && j == 0)
			j = 1;
	}
	return (j);
}

long int		atoi_push(const char *str)
{
	int					s;
	long int			r;

	r = 0;
	s = 1;

	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return ((r * s));
}

int 	*read_stack(int ar, char **av, int *j)
{
	size_t		i;
	long int	num;
	int 		*stack;

	i = 0;
	stack = (int *)malloc(sizeof(int) * (ar - 1));
	while (--ar)
	{
		arg_check(av[i + 1]);
		num = atoi_push(av[i + 1]);
		if (num > 2147483647 || num < -2147483648)
			ft_error();
		if (i)
			if (dub_check(stack, (int)num, i))
				(*j)++;
		stack[i++] = (int)num;
	}
	write(1, "C'est magnifique\n", 17); // test
	return (stack);
}

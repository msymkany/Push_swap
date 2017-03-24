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
	while (*str)
	{
		if (*str > '9' || *str < '0')
			ft_error();
		str++;
	}
}

void	dub_check(int *arr, int num, size_t i)
{
	while (i--)
	{
		if (*(arr++) == num)
			ft_error();
	}
}

long int		atoi_push(const char *str)
{
	int					s;
	unsigned int		r;

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
	return ((long int)(r * s));
}

int				main(int ar, char **av)
{
	size_t		i;
	long int	num;
	int 		arr_i[ar - 1];

	i = 1;
	if (ar == 1)
		ft_usage(av[0]);
	while (--ar)
	{
		arg_check(av[i]);
		num = atoi_push(av[i]);
		if (num > 2147483647 || num < -2147483648)
			ft_error();
		dub_check(arr_i, num, i);
		arr_i[i - 1] = (int)num;
		i++;
	}
	write(1, "C'est magnifique\n", 17);
	return (0);
}
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
		if (j == 0 && *arr++ > num)
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

int				main(int ar, char **av)
{
	size_t		i;
	int			j;
	long int	num;
	int 		arr_i[ar - 1];

	i = 0;
	j = 0;
	if (ar == 1)
		ft_usage(av[0]);
	else
	{
		while (--ar)
		{
			arg_check(av[i + 1]);
			num = atoi_push(av[i + 1]);
			if (num > 2147483647 || num < -2147483648)
				ft_error();
			if (i)
				if (dub_check(arr_i, num, i))
					j++;
			arr_i[i++] = (int)num;
		}
		ft_printf("%d\n", j);
		write(1, "C'est magnifique\n", 17); // test
	}
	return (0);
}
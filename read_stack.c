/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:54:01 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/13 20:40:09 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		arg_check(char *str)
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

int			dub_check(int *arr, int num, size_t i)
{
	int j;

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

long int	atoi_push(const char *str)
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

int			*read_stack(int ar, char **av, int *wrong, int j)
{
	size_t		i;
	long int	num;
	int			*stack;

	i = 0;
	stack = (int *)malloc(sizeof(int) * ar);
	while (j < ar)
	{
		arg_check(av[j]);
		num = atoi_push(av[j++]);
		if (num > 2147483647 || num < -2147483648)
			ft_error();
		if (i)
			if (dub_check(stack, (int)num, i))
				(*wrong)++;
		stack[i++] = (int)num;
	}
	return (stack);
}

int 	get_flags(int ar, char **av, char *flag)
{
	int  i;

	i = 1;
	while (i < ar && av[i][0] == '-')
	{
		if (ft_strequ(av[i], "-v"))
			(*flag) = (*flag) | 1;
		else if (ft_strequ(av[i], "-f"))
			(*flag) = (*flag) | 2;
		else if (ft_strequ(av[i], "-l"))
			(*flag) = (*flag) | 4;
		else if (ft_strequ(av[i], "-c"))
			(*flag) = (*flag) | 8;
		else if (ft_isdigit(av[i][1]))
			break ;
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

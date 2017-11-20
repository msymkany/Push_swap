/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:21:21 by msymkany          #+#    #+#             */
/*   Updated: 2017/04/10 15:21:28 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_stack_a_b(t_stack *a, t_stack *b)
{
	ft_printf("\033[45;1;39m   Stack a   |   Stack b   \033[0m\n");
	ft_printf("---------------------------\033[0m\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("\033[44m%12d |", a->num);
			a = a->next;
		}
		else if (!a && b)
			ft_printf("\033[44m             |");
		if (b)
		{
			ft_printf("%12d \033[0m\n", b->num);
			b = b->next;
		}
		else if (!b)
			ft_printf("             \033[0m\n");
	}
	ft_printf("\n");
}

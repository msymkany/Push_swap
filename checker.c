/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:56:09 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/25 17:56:12 by msymkany         ###   ########.fr       */
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
}

void	commands(char *com, t_stack **a, t_stack **b)
{
	if (!(ft_strcmp(com, "sa")))
		sa(a);
	else if (!(ft_strcmp(com, "sb")))
		sb(b);
	else if (!(ft_strcmp(com, "ss")))
		ss(a, b);
	else if (!(ft_strcmp(com, "pa")))
		pa(b, a);
	else if (!(ft_strcmp(com, "pb")))
		pb(a, b);
	else if (!(ft_strcmp(com, "ra")))
		ra(a);
	else if (!(ft_strcmp(com, "rb")))
		rb(b);
	else if (!(ft_strcmp(com, "rr")))
		rr(a, b);
	else if (!(ft_strcmp(com, "rra")))
		rra(a);
	else if (!(ft_strcmp(com, "rrb")))
		rrb(b);
	else if (!(ft_strcmp(com, "rrr")))
		rrr(a, b);
	else
		ft_error();
	print_stack_a_b(*a, *b); // test
}

int 	stack_check(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

void	checker(t_stack *a, int j)
{
	t_stack		*b;
	char 		*line;

	b = NULL;
	while (get_next_line(0, &line))
	{
		commands(line, &a, &b);
		if (j == 0)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		ft_strdel(&line);
	}
	if (j)
	{
		if (stack_check(a, b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "OK\n", 3);
}

//int		main(void)
//{
//	int 		stack[3] = {1, 2, -2147483648};
//	int			j;
//	t_stack		*a;
//
//	j = 1;
//	a = push_to_list(stack, 4);
//	print_list(a); //test
//	checker(a, j);
//	return (0);
//}

int		main(int ar, char **av)
{
	int 		*stack;
	int			j;
	t_stack		*a;

	j = 0;
	if (ar == 1)
		ft_usage(av[0]);
	else
	{
		stack = (read_stack(ar, av, &j));
		a = push_to_list(stack, ar);
		print_list(a); //test
		checker(a, j);
	}
	return (0);
}

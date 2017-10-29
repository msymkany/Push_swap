/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:29:13 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/18 15:37:10 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/libftprintf.h"

typedef struct		s_stack
{
	struct s_stack	*next;
	int     	num;
}			t_stack;

typedef struct		s_head
{
	t_stack		*self;
	int         len;
}			t_head;

void		ft_error(void);
void		ft_usage(char *name);

int 		*read_stack(int ar, char **av, int *j);

t_stack		*push_to_stack_a(int *arr, int n);
t_stack		*new_node(void);

void        sort_it(t_stack *a, int len_a, t_stack *b);

//operations
void	swap(t_stack **s);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **frst, t_stack **scnd);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **s);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse(t_stack **s);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//test
//void 	print_list(t_stack *list);
void	print_stack(int *stack, int ar);

#endif

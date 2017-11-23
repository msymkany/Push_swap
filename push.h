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

//100 - 700
//500 - 5300
//5 - 12

typedef struct		s_stack
{
	struct s_stack	*next;
	int				num;
}					t_stack;

typedef struct		s_op
{
	struct s_op		*next;
	char			*op;
}					t_op;


void				ft_error(void);
void				ft_usage(char *name);

int					*read_stack(int ar, char **av, int *j);
int					all_sorted(t_stack *a, t_stack *b);
int					stack_a_sorted(t_stack *a);
int					stack_b_sorted(t_stack *b);

t_op				*sort_it(t_stack *a, int length, int wrong);
void				sort_three_max(t_stack *a, t_stack *b, int len_a, t_op *op);
void				timsort(t_stack *a, int wrong, t_op *op);
void				merge_stacks(t_stack **a, t_stack **b, t_op *op);
int					count_misplaced(t_stack *a);
int					get_last_num(t_stack *st);


t_stack				*push_to_list(int *arr, int n);
t_stack				*new_node(void);
void				del_stack(t_stack *a);

t_op				*new_node_op(char *op);
void				*add_op(t_op *list, char *op);
void				del_op(t_op *op);

void				quicksort(t_stack *a, t_stack *b, t_op *op);

//operations
void				swap(t_stack **s);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				push(t_stack **frst, t_stack **scnd);
void				pa(t_stack **b, t_stack **a);
void				pb(t_stack **a, t_stack **b);
void				rotate(t_stack **s);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				reverse(t_stack **s);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				print_stack_a_b(t_stack *a, t_stack *b);
void				commands(char *com, t_stack **a, t_stack **b);

#endif

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

void				ft_error(void);
void				ft_usage(char *name);

int					*read_stack(int ar, char **av, int *j);
int					all_sorted(t_stack *a, t_stack *b);
int					stack_a_sorted(t_stack *a);
int					stack_b_sorted(t_stack *b);

void				sort_it(t_stack *a, int	length, int wrong, char debug);
void				sort_three_max(t_stack *a, t_stack *b, int len_a, char debug);
void				timsort(t_stack *a, int wrong, char debug);
void				merge_stacks(t_stack **a, t_stack **b, char debug);
int					count_misplaced(t_stack *a);
int					get_last_num(t_stack *st);
t_stack				*push_to_list(int *arr, int n);
t_stack				*new_node(void);

void				quicksort(t_stack *a, t_stack *b, char debug);

void				swap(t_stack **s);
void				sa(t_stack **a, t_stack **b, char print, char debug);
void				sb(t_stack **a, t_stack **b, char print, char debug);
void				ss(t_stack **a, t_stack **b, char print, char debug);
void				push(t_stack **frst, t_stack **scnd);
void				pa(t_stack **b, t_stack **a, char print, char debug);
void				pb(t_stack **a, t_stack **b, char print, char debug);
void				rotate(t_stack **s);
void				ra(t_stack **a, t_stack **b, char print, char debug);
void				rb(t_stack **a, t_stack **b, char print, char debug);
void				rr(t_stack **a, t_stack **b, char print, char debug);
void				reverse(t_stack **s);
void				rra(t_stack **a, t_stack **b, char print, char debug);
void				rrb(t_stack **a, t_stack **b, char print, char debug);
void				rrr(t_stack **a, t_stack **b, char print, char debug);

void				print_stack_a_b(t_stack *a, t_stack *b);

#endif

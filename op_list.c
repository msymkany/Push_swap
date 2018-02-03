/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:41:52 by msymkany          #+#    #+#             */
/*   Updated: 2017/11/23 16:41:55 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_op		*new_node_op(char *op)
{
	t_op		*new;

	new = (t_op *)malloc(sizeof(t_op));
	if (new)
	{
		new->next = NULL;
		new->op = ft_strdup(op);
	}
	return (new);
}

void		add_op(t_op **list, char *op, t_stack **a, t_stack **b)
{
	t_op *ptr;

	ptr = *list;
	commands(op, a, b);
//	print_stack_a_b(*a, *b); // test
	if (ptr)
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		if ((ft_strequ(op, "sa") && ft_strequ(ptr->op, "sb")) ||
			(ft_strequ(op, "sb") && ft_strequ(ptr->op, "sa")))
			ft_strcpy(ptr->op, "ss");
		else if ((ft_strequ(op, "ra") && ft_strequ(ptr->op, "rb")) ||
				 (ft_strequ(op, "rb") && ft_strequ(ptr->op, "ra")))
			ft_strcpy(ptr->op, "rr");
		else if ((ft_strequ(op, "rra") && ft_strequ(ptr->op, "rrb")) ||
				 (ft_strequ(op, "rrb") && ft_strequ(ptr->op, "rra")))
			ft_strcpy(ptr->op, "rrr");
		else
			ptr->next = new_node_op(op);
	}
	else
		*list = new_node_op(op);
}
void		add_op_new(t_all *x, char *op)
{
	t_op *ptr;

	ptr = x->op;
	commands(op, &(x->a), &(x->b));
//	print_stack_a_b(x->a, x->b); // test
	if (ptr)
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		if ((ft_strequ(op, "sa") && ft_strequ(ptr->op, "sb")) ||
			(ft_strequ(op, "sb") && ft_strequ(ptr->op, "sa")))
			ft_strcpy(ptr->op, "ss");
		else if ((ft_strequ(op, "ra") && ft_strequ(ptr->op, "rb")) ||
				 (ft_strequ(op, "rb") && ft_strequ(ptr->op, "ra")))
			ft_strcpy(ptr->op, "rr");
		else if ((ft_strequ(op, "rra") && ft_strequ(ptr->op, "rrb")) ||
				 (ft_strequ(op, "rrb") && ft_strequ(ptr->op, "rra")))
			ft_strcpy(ptr->op, "rrr");
		else
			ptr->next = new_node_op(op);
	}
	else
		x->op = new_node_op(op);
}

void		del_op(t_op *op)
{
	t_op	*ptr;

	ptr = NULL;
	ptr = op;
	while (ptr)
	{
		ptr = ptr->next;
		ft_strdel(&op->op);
		free(op);
		op = NULL;
		op = ptr;
	}
}

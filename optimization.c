/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:09:26 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/06 19:09:30 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#define NOP p->next->op
#define NNOP p->next->next->op
#define OP p->op

void		del_next_node(t_op *ptr)
{
	t_op	*p;

	p = NULL;
	p = ptr->next->next;
	ft_strdel(&ptr->next->op);
	free(ptr->next);
	ptr->next = NULL;
	ptr->next = p;
}

void		del_two_next_node(t_op *p)
{
	del_next_node(p);
	del_next_node(p);
}

void		check_pairs_2(t_op *p)
{
	if ((ft_strequ(NOP, "ra") && ft_strequ(NNOP, "rra")) ||
		(ft_strequ(NOP, "rra") && ft_strequ(NNOP, "ra")))
		del_two_next_node(p);
	else if ((ft_strequ(NOP, "rb") && ft_strequ(NNOP, "rrb")) ||
			 (ft_strequ(NOP, "rrb") && ft_strequ(NNOP, "rb")))
		del_two_next_node(p);
	else if ((ft_strequ(NOP, "rr") && ft_strequ(NNOP, "rrr")) ||
			(ft_strequ(NOP, "rrr") && ft_strequ(NNOP, "rr")))
		del_two_next_node(p);
	else if ((ft_strequ(NOP, "pb") && ft_strequ(NNOP, "pa")) ||
			 (ft_strequ(NOP, "pa") && ft_strequ(NNOP, "pb")))
		del_two_next_node(p);
	else if ((ft_strequ(NOP, "sa") && ft_strequ(NNOP, "sa")) ||
			 (ft_strequ(NOP, "sb") && ft_strequ(NNOP, "sb")))
		del_two_next_node(p);
}

void		check_pairs(t_op *p)
{
	if ((ft_strequ(OP, "sa") && ft_strequ(NOP, "sb")) ||
		(ft_strequ(OP, "sb") && ft_strequ(NOP, "sa")))
	{
		ft_strcpy(OP, "ss");
		del_next_node(p);
	}
	else if ((ft_strequ(OP, "ra") && ft_strequ(NOP, "rb")) ||
			 (ft_strequ(OP, "rb") && ft_strequ(NOP, "ra")))
	{
		ft_strcpy(OP, "rr");
		del_next_node(p);
	}
	else if ((ft_strequ(OP, "rra") && ft_strequ(NOP, "rrb")) ||
			 (ft_strequ(OP, "rrb") && ft_strequ(NOP, "rra")))
	{
		ft_strcpy(OP, "rrr");
		del_next_node(p);
	}
}

void		optimize_op(t_op *op)
{
	t_op	*p;

	p = op;
	while (p->next)
	{
		if (p->op)
		{
			check_pairs(p);
			if (p->next->next)
			check_pairs_2(p);
		}
		p = p->next;
	}
}

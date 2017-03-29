/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:23:49 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/27 15:23:52 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_stack **s)
{
	int 		n;

	if (*s && (*s)->next)
	{
		n = (*s)->num;
		(*s)->num = (*s)->next->num;
		(*s)->next->num = n;
	}
}

void	push(t_stack **frst, t_stack **scnd)
{
	t_stack		*st;

	st = *frst;
	if (*frst)
	{
		*frst = *frst->next;
		st->next = *scnd;
		*scnd = st;
	}
}

void	rotate(t_stack **s)
{
	t_stack		*frst_el;
	t_stack		*ptr;

	frst_el = *s;
	ptr = *s;
	if (*s && (*s)->next)
	{
		*s = *s->next;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = frst_el;
		frst_el->next = NULL;
	}
}

void	reverse(t_stack **s)
{
	t_stack		*last_el;
	t_stack		*ptr;

	ptr = *s;
	if (*s && (*s)->next)
	{
		while (ptr->next->next)
			ptr = ptr->next;
		last_el = ptr->next;
		ptr->next = NULL;
		last_el->next = *s;
		*s = last_el;
	}
}

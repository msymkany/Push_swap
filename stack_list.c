/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:56:39 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/25 17:56:59 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack		*new_node(void)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(stack_t));
	if (new)
		new->next = NULL;
	return (new);
}

t_stack		*push_to_list(int *arr, int n)
{
	t_stack		*head;
	t_stack		*next;

	next = new_node();
	head = next;
	while (--n > 1)
	{
		next->num = *arr++;
		next->next = new_node();
		next = next->next;
	}
	next->num = *arr++;
	return (head);
}
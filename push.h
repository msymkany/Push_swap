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
	int				num;
}					t_stack;

void	ft_error(void);
void	ft_usage(char *name);


#endif

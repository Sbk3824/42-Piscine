/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:39:14 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/07 16:39:22 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

typedef struct	s_stack
{
	char		**data;
	int			top;
}				t_stack;

void			stack_init(t_stack *stack, int size);
void			stack_push(t_stack *stack, char *str);
char			*stack_top(t_stack *stack);
char			*stack_pop(t_stack *stack);
void			stack_free(t_stack *stack);

#endif

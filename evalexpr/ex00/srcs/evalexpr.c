/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:40:20 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/07 23:10:21 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "evalexpr.h"

t_stack g_opstack;
t_stack g_numstack;

int		push_number(char *str)
{
	int len;

	len = is_number(str);
	stack_push(&g_numstack, ft_strncpy(str, len));
	return (len);
}

void	evaluate(void)
{
	int		op1;
	int		op2;
	char	op;
	t_func	f;

	op2 = ft_atoi(stack_pop(&g_numstack));
	op1 = ft_atoi(stack_pop(&g_numstack));
	op = *stack_pop(&g_opstack);
	f = get_operator(op);
	stack_push(&g_numstack, ft_itoa(f(op1, op2)));
}

void	fill_stacks(char *str)
{
	while (*str)
	{
		if (is_number(str))
			str += push_number(str) - 1;
		else if (get_operator(*str))
		{
			while (stack_top(&g_opstack)
			&& priority(*str) <= priority(*stack_top(&g_opstack)))
				evaluate();
			stack_push(&g_opstack, ft_strncpy(str, 1));
		}
		else if (*str == '(')
			stack_push(&g_opstack, ft_strncpy(str, 1));
		else if (*str == ')')
		{
			while (*stack_top(&g_opstack) != '(')
				evaluate();
			stack_pop(&g_opstack);
		}
		str++;
	}
}

void	eval_stacks(void)
{
	while (stack_top(&g_opstack))
		evaluate();
}

int		eval_expr(char *str)
{
	stack_init(&g_opstack, ft_strlen(str) + 1);
	stack_init(&g_numstack, ft_strlen(str) + 1);
	fill_stacks(str);
	eval_stacks();
	return (stack_top(&g_numstack)
		? ft_atoi(stack_pop(&g_numstack)) : 0);
}

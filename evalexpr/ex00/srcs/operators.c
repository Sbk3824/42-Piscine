/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:57:26 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/07 19:57:13 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "evalexpr.h"

t_func	g_func[] = { ft_add, ft_sub, ft_div, ft_mul, ft_mod };

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

t_func	get_operator(char op)
{
	int i;

	i = -1;
	while (++i < 5)
		if (op == G_OPERATORS[i])
			return (g_func[i]);
	return (0);
}

int		priority(char op)
{
	if (op == '/' || op == '*' || op == '%')
		return (2);
	else if (op == '-' || op == '+')
		return (1);
	else
		return (0);
}

int		is_number(char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

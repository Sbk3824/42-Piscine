/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:00:31 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/04 21:01:03 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list		*current;
	t_list		*tmp;

	current = *begin_list;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*begin_list = NULL;
}

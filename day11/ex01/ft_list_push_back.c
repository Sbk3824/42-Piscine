/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:58:30 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/04 17:58:58 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*current;

	current = *begin_list;
	if (!current)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (current->next != 0)
		current = current->next;
	current->next = ft_create_elem(data);
}

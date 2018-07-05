/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:26:06 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/04 17:09:25 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		count;

	count = 0;
	if (!begin_list)
		return (0);
	while (begin_list->next != 0)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count + 1);
}

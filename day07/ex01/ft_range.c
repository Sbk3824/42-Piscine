/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:47:27 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/28 16:19:48 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int i;

	range = NULL;
	if (min < max)
	{
		range = (int*)malloc(sizeof(*range) * (max - min));
		i = 0;
		while (min < max)
		{
			range[i] = min;
			min++;
			i++;
		}
	}
	return (range);
}

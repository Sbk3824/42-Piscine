/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:55:03 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/28 15:42:07 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*duplicate;
	int		len;

	len = 0;
	while (src[len])
		len++;
	duplicate = (char*)malloc(sizeof(*duplicate) * (len + 1));
	len = 0;
	while (src[len])
	{
		duplicate[len] = src[len];
		len++;
	}
	duplicate[len] = '\0';
	return (duplicate);
}

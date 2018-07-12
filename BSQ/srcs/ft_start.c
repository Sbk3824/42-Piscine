/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 14:10:58 by cmutti            #+#    #+#             */
/*   Updated: 2015/09/24 21:07:49 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_bsq.h"

int		ft_get_width(char *st, t_instr inf, int width)
{
	int		i;
	int		c;
	int		lines;

	i = inf.length - 1;
	printf("Finding the width...:");
	c = 0;
	lines = 0;
	while (st[++i])
	{
		if (st[i] == '\n')
		{
			if (width != -1 && width != c)
				return (-1);
			width = c;
			c = 0;
			lines++;
		}
		else if (st[i] != inf.empty && st[i] != inf.obst)
			return (-1);
		else if (c == 2147483647)
			return (-1);
		else
			c++;
	}
	printf("%d\n",width);
	if (lines == inf.height)
		return (width);
	return (-1);
}

void	ft_start(char *str)
{
	t_instr		*info;
	t_record	*record;
	int			width;

	printf("\nStarting the process with string...\n");
	info = ft_first_line(str);
	record = ft_new_record();
	if (info)
	{
		width = -1;
		info->width = ft_get_width(str, *info, width);
		if (info->width > 0)
		{
			printf("Width is greater than 0, continue the process...");
			ft_get_record(info, str, record);
			ft_fill_board(record, str, info);
			ft_put_result(str, info->length);
			free(str);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}

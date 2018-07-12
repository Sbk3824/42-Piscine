/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:49:52 by cmutti            #+#    #+#             */
/*   Updated: 2015/09/24 17:31:01 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_bsq.h"

void		ft_get_record(t_instr *info, char *str, t_record *record)
{
	int		position[2];
	int		max;

		printf("\n\n-----------Getting Record------------\n");
	printf("--Board Details--\nHeight:%d\nWidth:%d\n\n",info->height,info->width);
	position[1] = 0;
	while (position[1] + record->max < info->height)
	{
		position[0] = 0;
		while (position[0] + record->max < info->width)
		{
			printf("\ncalling ft_check_case with size %d pos[1] %d and pos[0] %d ...\n", record->max,position[1],position[0]);
			max = ft_check_case(str, info, position, record->max);
			printf("max:%d\n",max);
			if (max > record->max)
			{
				printf("max > record->max, Entered if loop\n");
				record->max = max;
				record->x = position[0];
				record->y = position[1];
			}
			else if (max < 0)
			{
				printf("max is less than 0:%d\n",max);
				if (position[0] + -max < info->width)
				{
					printf("position[0] + -max < info->width\n");
					position[0] = position[0] + -max;
					printf("new position:%d\n",position[0]);
				}
			}
			position[0]++;
		}
		position[1]++;
	}
}

int			ft_check_case(char *str, t_instr *info, int position[2], int size)
{
	int		i;
	int		temp;

	printf("within ft_check_case... \n");
	i = size + 1;
	while (1)
	{
		printf("i=size+1:\t%d\n",i);
		printf("position[1]:%d\n",position[1]);
		printf("position[0]:%d\n",position[0]);
		if (position[0] + i > info->width)
			return (i - 1);
		else if (position[1] + i - 1 >= info->height)
			return (i - 1);
		temp = ft_check_square(str, position, info, i);
		printf("temp:%d\n",temp);
		if (temp > 0)
		{
			i++;
			while (ft_bigger_sqr(str, position, info, i))
				i++;
			printf("i:%d\n",i);
			return (i - 1);
		}
		else
			return (temp);
	}
}

int			ft_check_square(char *str, int position[2], t_instr *info, int size)
{
	int i;
	int j;
	int start;
	int res;

	printf("\twithin ft_check_square....\n");
	start = info->length + position[0] + (position[1]) * (info->width + 1);
	printf("\tStart:%d\n",start);
	i = size - 1;
	printf("\ti:%d\n",i);
	while (i >= 0)
	{
		j = 0;
		while (j < size)
		{
			res = start + i + j * (info->width + 1);
			if (str[res] == info->obst)
				return (-i);
			else if (str[res] == '\n')
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

void		ft_fill_board(t_record *record, char *str, t_instr *info)
{
	int		x;
	int		y;
	int		position;
	int 	res;

	printf("\nFilling Board...\n");
	y = 0;
	position = info->length + record->x + (record->y) * (info->width + 1);
	printf("Position:%d\n",position);
	printf("record->max:%d\n",record->max);
	while (y < record->max)
	{
		x = 0;
		while (x < record->max)
		{
			res = position + x + y * (info->width + 1);
			printf("Res:%d\n",res);
			str[res] = info->full;
			x++;
		}
		y++;
	}
	printf("X:%d\n",x);
	printf("Y:%d\n",y);
}

t_record	*ft_new_record(void)
{
	t_record	*new;

	new = (t_record *)malloc(sizeof(t_record));
	if (new)
	{
		new->x = 0;
		new->y = 0;
		new->max = 0;
	}
	return (new);
}

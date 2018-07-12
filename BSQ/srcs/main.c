/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 22:37:37 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/11 23:21:33 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#define BUFF1 1000000
#define BUFF2 8000000

void	ft_concat(char *dest, char *src, int *size, int buff_size)
{
	int		i;
	int		c;

	i = 0;
	if ((*size) > buff_size && (*size) % buff_size == 0)
	{
		if (dest[*size - buff_size])
			i = *size - buff_size;
	}
	c = 0;
	while (dest[i])
		i++;
	while (src[c] && c < buff_size)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	while (c >= 0)
	{
		src[c] = '\0';
		c--;
	}
	dest[i] = '\0';
}

void	ft_infinity_check(int *size, char *str, int buf)
{
	if (*size == buf)
	{
		if (ft_strlen_mod(str) == 0)
		{
			ft_putstr("");
			*size = -1;
		}
	}
}

char	*ft_read(int fd, int buff_size)
{
	char	buff[buff_size + 1];
	char	*str;
	char	*temp;
	int		size;

	size = 0;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	temp = (char*)malloc(sizeof(*str) * (size + 1));
	str[0] = 0;
	temp[0] = 0;
	while (read(fd, buff, buff_size) && str && temp && size >= 0)
	{
		size += buff_size;
		ft_strcpy(temp, str);
		free(str);
		str = (char*)malloc(sizeof(*str) * (size + 1));
		ft_strcpy(str, temp);
		ft_concat(str, buff, &size, buff_size);
		str[size] = '\0';
		free(temp);
		temp = (char*)malloc(sizeof(*temp) * (size + 1));
		ft_infinity_check(&size, str, buff_size);
	}
	free(temp);
	return (str);
}

void	temp_read(int fd)
{
	char *str;

	str = ft_read(fd, BUFF2);
	ft_start(str);
	close(fd);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		fd;

	str = NULL;
	i = 0;
	if (argc != 1)
		while (++i < argc)
		{
			if (i > 1)
				ft_putchar('\n');
			fd = open(argv[i], O_RDONLY);
			if (fd > 0)
			{
				temp_read(fd);
			}
			else
				ft_putstr("map error\n");
		}
	else
	{
		str = ft_read(0, BUFF1);
		ft_start(str);
	}
	return (0);
}

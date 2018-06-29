/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:39:25 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/29 15:38:04 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	*final;
	char	temp;

	start = str;
	end = str;
	final = str;
	while (*end != '\0')
	{
		end++;
	}
	end--;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (final);
}

char	*ft_trim(char *a)
{
	int j;

	while (a[0] <= 32 && a[0] >= 1)
	{
		j = 1;
		while (a[j] != '\0')
		{
			a[j - 1] = a[j];
			j++;
		}
		a[j - 1] = '\0';
	}
	return (a);
}

char	*ft_strlowcase(char *str)
{
	int pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 'A' && str[pos] <= 'Z')
		{
			str[pos] += 32;
		}
		pos++;
	}
	return (str);
}

int		ft_strcmp(char *str1, char *str2)
{
	if (*str1 != '\0' && *str1 == *str2)
	{
		return (ft_strcmp(++str1, ++str2));
	}
	return (*str1 - *str2);
}

int		main(int argc, char **argv)
{
	char	*temp;
	int		i;

	i = 0;
	while (++i < argc)
	{
		temp = ft_strlowcase(ft_trim(argv[i]));
		temp = ft_strrev(ft_trim(ft_strrev(temp)));
		if (ft_strcmp(temp, "president") == 0 ||
			ft_strcmp(temp, "bauer") == 0 ||
			ft_strcmp(temp, "attack") == 0)
			write(1, "ALERT!!!\n", 9);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 11:53:08 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/29 12:23:04 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(char *str)
{
	int w;
	int is_last_space;

	w = 0;
	is_last_space = 1;
	while (*str)
	{
		if (!(*str == ' ' || *str == '\t' || *str == '\n') && is_last_space)
		{
			w++;
			is_last_space = 0;
		}
		else if (*str == ' ' || *str == '\t' || *str == '\n')
			is_last_space = 1;
		str++;
	}
	return (w);
}

int		get_next_word_pos(char *str, int pos)
{
	while (str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n')
		pos++;
	return (pos);
}

int		get_word_length(char *str, int pos)
{
	int length;

	length = 0;
	while (!(str[pos + length] == ' ' || str[pos + length] == '\t'
		|| str[pos + length] == '\n' || str[pos + length] == '\0'))
		length++;
	return (length);
}

int		set_word(char **res, int n, char *str, int pos)
{
	int l;
	int p;
	int i;

	p = get_next_word_pos(str, pos);
	l = get_word_length(str, p);
	res[n] = (char*)malloc(sizeof(char) * l + 1);
	i = 0;
	while (i < l)
	{
		res[n][i] = str[p + i];
		i++;
	}
	res[n][i] = '\0';
	return (p + l);
}

char	**ft_split_whitespaces(char *str)
{
	char	**res;
	int		p;
	int		i;
	int		words;

	i = 0;
	p = 0;
	words = count_words(str);
	res = (char **)malloc(sizeof(char*) * (words + 1));
	while (i < words)
	{
		p = set_word(res, i, str, p);
		i++;
	}
	res[i] = 0;
	return (res);
}

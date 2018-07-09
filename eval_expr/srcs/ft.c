/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:40:12 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/07 18:44:03 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define ABS(x) (x < 0 ? -x : x)

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

char	*ft_strncpy(char *src, unsigned int n)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	while (src[i] && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		ft_atoi(char *str)
{
	int n;
	int i;
	int isnegative;

	n = 0;
	i = 0;
	isnegative = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	if (isnegative == 1)
		return (-n);
	return (n);
}

char	*ft_itoa(int nbr)
{
	unsigned int	n;
	char			*res;
	char			*start;
	long			pow;

	pow = 1;
	res = (char *)malloc(sizeof(char) * (12));
	start = res;
	if (nbr < 0)
	{
		*res = '-';
		res++;
	}
	n = ABS(nbr);
	while (n >= pow * 10)
		pow *= 10;
	while (pow)
	{
		*res = n / pow + '0';
		n = n % pow;
		pow /= 10;
		res++;
	}
	*res = '\0';
	return (start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:12:01 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/29 16:12:17 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	int				i;
	unsigned int	res;
	unsigned int	n;

	res = 0;
	i = 0;
	n = (unsigned int)value;
	while (i < 32)
	{
		res += n % 2;
		n /= 2;
		i++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:52:11 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/29 13:58:23 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_collatz_conjecture(unsigned int base)
{
	unsigned int count;

	count = 0;
	if (base % 2)
	{
		base *= 3;
		base++;
	}
	else
		base /= 2;
	if (base > 1)
		count = ft_collatz_conjecture(base);
	return (count + 1);
}

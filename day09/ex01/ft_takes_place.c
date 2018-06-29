/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:27:29 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/28 21:52:01 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*pm_get(int hour, char pm[5])
{
	if (hour >= 12 && hour < 24)
		pm = "P.M.";
	else
		pm = "A.M.";
	return (pm);
}

void	ft_takes_place(int hour)
{
	int		h12;
	int		h12_1;
	char	pm[5];

	h12 = hour > 12 ? hour - 12 : hour;
	h12_1 = hour + 1 > 12 ? hour - 11 : hour + 1;
	if (h12_1 == 13)
		h12_1 = 1;
	if (hour == 0)
		h12 = 12;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %s AND %d.00 %s\n", h12, pm_get(hour, pm),
			h12_1, pm_get(hour + 1, pm));
}

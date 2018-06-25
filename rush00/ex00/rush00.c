/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:56:24 by sosong            #+#    #+#             */
/*   Updated: 2018/06/24 20:17:06 by sosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print0(int x, int y, int i, int j)
{
	if ((i == 0 || ((i + 1) == y)) && (j == 0 || ((j + 1) == x)))
		ft_putchar('o');
	else if (i > 0 || j > 0)
	{
		if (j == 0 || ((j + 1) == x))
			ft_putchar('|');
		else if (i == 0 || ((i + 1) == y))
			ft_putchar('-');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int i;
	int j;

	if (x == 0 || y == 0)
		return ;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			print0(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

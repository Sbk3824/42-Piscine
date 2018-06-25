/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:31:31 by sosong            #+#    #+#             */
/*   Updated: 2018/06/24 20:13:53 by sosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print4(int x, int y, int i, int j)
{
	if ((i == 0 && j == 0) || (i + 1 == y && j + 1 == x))
	{
		if ((i != 0 && j == 0) || (i == 0 && j != 0))
			ft_putchar('C');
		else
			ft_putchar('A');
	}
	else if ((i == 0 && j + 1 == x) || (j == 0 && i + 1 == y))
		ft_putchar('C');
	else if (i == 0 || i + 1 == y)
		ft_putchar('B');
	else if (j == 0 || j + 1 == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	if (x == 0 || y == 0)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			print4(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

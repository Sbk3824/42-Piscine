/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:45:15 by sosong            #+#    #+#             */
/*   Updated: 2018/06/24 20:24:45 by sosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print3(int x, int y, int i, int j)
{
	if ((i == 0 && j == 0) || (j == 0 && i + 1 == y))
		ft_putchar('A');
	else if ((i == 0 && j + 1 == x) || (j + 1 == x && i + 1 == y))
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
			print3(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

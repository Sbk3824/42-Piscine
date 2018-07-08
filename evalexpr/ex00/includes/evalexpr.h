/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:37:39 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/07 16:38:36 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_H
# define EVALEXPR_H

# include <stdlib.h>

typedef	int	(*t_func)(int x, int y);

int			ft_add(int x, int y);
int			ft_div(int x, int y);
int			ft_mod(int x, int y);
int			ft_mul(int x, int y);
int			ft_sub(int x, int y);

# define G_OPERATORS "+-/*%"

int			eval_expr(char *str);

int			is_digit(char c);

void		ft_putchar(char c);
void		ft_putnbr(int nb);
char		*ft_strncpy(char *src, unsigned int n);
char		*ft_itoa(int nbr);
int			ft_atoi(char *str);
int			ft_strlen(char *str);

t_func		get_operator(char op);
int			priority(char op);
void		evaluate(void);
int			is_number(char *str);
int			push_number(char *str);
void		fill_stacks(char *str);
void		eval_stacks(void);

#endif

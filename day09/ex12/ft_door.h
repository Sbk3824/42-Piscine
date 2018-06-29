/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:04:48 by skuntoji          #+#    #+#             */
/*   Updated: 2018/06/29 16:05:02 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# define TRUE 1
# define OPEN 1
# define CLOSE 0
# define EXIT_SUCCESS 0

typedef struct	s_door
{
	int			state;
}				t_door;

int				is_door_open(t_door *door);
int				is_door_close(t_door *door);
int				open_door(t_door *door);
int				close_door(t_door *door);
void			ft_putstr(char *str);

#endif

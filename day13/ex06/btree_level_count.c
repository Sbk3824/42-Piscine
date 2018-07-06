/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuntoji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:17:46 by skuntoji          #+#    #+#             */
/*   Updated: 2018/07/06 14:17:52 by skuntoji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int ldepth;
	int rdepth;

	if (root)
	{
		ldepth = btree_level_count(root->left);
		rdepth = btree_level_count(root->right);
		return ((ldepth > rdepth) ? ldepth + 1 : rdepth + 1);
	}
	return (0);
}

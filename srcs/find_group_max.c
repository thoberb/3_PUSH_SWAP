/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_group_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:33:53 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/03 13:34:38 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_group_max(t_pile **b, int group_max)
{
	t_pile	*tmp_b;
	int		nb;

	nb = 0;
	tmp_b = (*b);
	while (tmp_b)
	{
		if (tmp_b->groupe == group_max)
			nb += 1;
		tmp_b = tmp_b->next;
	}
	return (nb);
}

int	find_group_max(t_pile **b)
{
	t_pile	*tmp_b;
	int		max;

	tmp_b = (*b);
	if (tmp_b)
	{
		max = tmp_b->groupe;
		while (tmp_b)
		{
			if (tmp_b->groupe > max)
				max = tmp_b->groupe;
			tmp_b = tmp_b->next;
		}
		return (max);
	}
	return (0);
}

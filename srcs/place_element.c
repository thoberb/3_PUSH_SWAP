/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:44:13 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/08 15:59:58 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotate(t_pile **a, t_pile **b, int count_ra, int count_rb)
{
	if (count_ra < 0 && count_rb < 0)
	{
		while (count_ra < 0 && count_rb < 0)
		{
			rrr(a, b);
			count_ra++;
			count_rb++;
		}
	}
	if (count_ra > 0 && count_rb > 0)
	{
		while (count_ra > 0 && count_rb > 0)
		{
			rr(a, b);
			count_ra--;
			count_rb--;
		}
	}
}

int	put_element_on_top(t_pile **b, int elem, int sizeb)
{
	int	c;

	if (elem != (*b)->index)
	{
		c = ft_count_rb(b, elem, sizeb);
		if (c < 0)
		{
			while (elem != (*b)->index)
				rrb(b);
		}
		else
		{
			while (elem != (*b)->index)
				rb(b);
		}
	}
	return (elem);
}

void	rotate_pour_encadrer(t_pile **a, int elem, int sizea)
{
	int	count_ra;

	count_ra = ft_count_ra(a, elem, sizea);
	if (count_ra > 0)
	{
		while (count_ra > 0)
		{
			ra(a);
			count_ra--;
		}
	}
	else
	{
		while (count_ra < 0)
		{
			rra(a);
			count_ra++;
		}
	}
}

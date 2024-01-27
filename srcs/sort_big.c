/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:41:51 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/08 16:01:21 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_pile **a, t_pile **b, int size, int sizeb)
{
	int		group_max;
	int		element_index;

	element_index = 0;
	if (sizeb > 0)
	{
		group_max = find_group_max(b);
		while (find_group_max(b) == group_max)
		{
			element_index = find_elem(a, b, size, sizeb);
			double_rotate(a, b, ft_count_ra(a, element_index, size),
				ft_count_rb(b, element_index, sizeb));
			element_index = put_element_on_top(b, element_index, sizeb);
			rotate_pour_encadrer(a, element_index, size);
			pa(a, b);
			sizeb--;
			size++;
		}
		sort(a, b, size, sizeb);
	}
}

int	push_b(t_pile **a, t_pile **b, int median, int limit)
{
	if ((*a)->index <= limit)
	{
		pb(a, b);
		if (((*b)->index > median) && (*b)->index <= limit)
			(*b)->groupe = limit;
		else
		{
			(*b)->groupe = median;
			rb(b);
		}
		return (1);
	}
	else
		ra(a);
	return (0);
}

void	pre_sort(t_pile **a, t_pile **b, int size)
{
	int	div;
	int	reste;
	int	size_a;
	int	n;

	size_a = size;
	while (size_a != 3)
	{
		div = size_a / 3;
		reste = size_a % 3;
		n = size_a;
		if (div < 3)
			size_a -= push_b(a, b, 0, (size - 3));
		else
		{
			while (size_a > n - (2 * div))
			{
				size_a -= push_b(a, b, \
				(size - (2 * div + reste)), (size - (div + reste)));
			}
		}
	}
}

void	sort_big(t_pile **a, t_pile **b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	int		size;
	int		sizeb;

	tmp_a = (*a);
	size = ft_lstsize(tmp_a);
	put_lst_in_tab(a, size);
	pre_sort(a, b, size);
	sort_small(a, b);
	tmp_b = (*b);
	sizeb = ft_lstsize(tmp_b);
	sort(a, b, 3, sizeb);
	while ((*a)->index != 1)
		rra(a);
}

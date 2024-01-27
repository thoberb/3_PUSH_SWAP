/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:17:53 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/08 15:56:58 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pas_encadre(t_pile *first, t_pile *last, int element)
{
	if ((element < first->index && first->index < last->index)
		|| (first->index > element && element > last->index))
		return (1);
	return (0);
}

int	ft_count_ra(t_pile **a, int element, int sizea)
{
	t_pile	*first;
	t_pile	*last;
	int		count_ra;

	count_ra = 0;
	first = (*a);
	last = ft_lstlast(*a);
	while (pas_encadre(first, last, element) == 0)
	{
		count_ra++;
		last = first;
		first = first->next;
	}
	if (count_ra > sizea / 2)
		count_ra = (sizea - count_ra) * (-1);
	return (count_ra);
}

int	ft_count_rb(t_pile **b, int element, int sizeb)
{
	t_pile	*tmp_b;
	int		count_rb;

	count_rb = 0;
	tmp_b = (*b);
	while (tmp_b->index != element)
	{
		tmp_b = tmp_b->next;
		count_rb++;
	}
	if (count_rb > sizeb / 2)
		count_rb = (sizeb - count_rb) * (-1);
	return (count_rb);
}

int	count_coups(int count_ra, int count_rb, int sizea, int sizeb)
{
	(void)sizea;
	(void)sizeb;
	if (count_ra < 0)
		count_ra *= (-1);
	if (count_rb < 0)
		count_rb *= (-1);
	return (count_ra + count_rb);
}

int	find_elem(t_pile **a, t_pile **b, int sizea, int sizeb)
{
	int		elem;
	int		count;
	int		count_new;
	int		group_max;
	t_pile	*tmp_b;

	elem = 0;
	count = 2147483647;
	tmp_b = (*b);
	group_max = find_group_max(b);
	while (tmp_b)
	{
		if (tmp_b->groupe == group_max)
		{
			count_new = count_coups(ft_count_ra(a, tmp_b->index, sizea),
					ft_count_rb(b, tmp_b->index, sizeb), sizea, sizeb);
			if (count_new < count)
			{
				count = count_new;
				elem = tmp_b->index;
			}
		}
		tmp_b = tmp_b->next;
	}
	return (elem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:42:08 by bberthod          #+#    #+#             */
/*   Updated: 2023/04/04 12:15:19 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_sort(t_pile **a, t_pile **b)
{
	if ((*b)->nbr < (*a)->nbr)
		pa(a, b);
	else if ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr)
	{
		pa(a, b);
		sa(a);
	}
}

void	sort_three(t_pile **a)
{
	while (a_is_sorted(a) == 0)
	{
		if ((*a)->nbr > (*a)->next->nbr)
		{
			if (((*a)->next->nbr < (*a)->next->next->nbr)
				&& ((*a)->nbr > (*a)->next->next->nbr))
				ra(a);
			else
				sa(a);
		}
		else if (((*a)->nbr < (*a)->next->nbr)
			&& ((*a)->next->nbr > (*a)->next->next->nbr))
		{
			if ((*a)->nbr > (*a)->next->next->nbr)
				rra(a);
			else
				ra(a);
		}
	}
}

void	sort_four(t_pile **a, t_pile **b)
{
	pb(a, b);
	sort_three(a);
	if (((*b)->nbr < (*a)->nbr)
		|| ((*b)->nbr > (*a)->nbr && (*b)->nbr < (*a)->next->nbr))
		same_sort(a, b);
	else if ((*b)->nbr > (*a)->next->next->nbr)
	{
		pa(a, b);
		ra(a);
	}
	else
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
}

void	sort_five(t_pile **a, t_pile **b)
{
	int	size;

	size = 5;
	put_lst_in_tab(a, size);
	while (size > 3)
	{
		while ((*a)->index != 1 && (*a)->index != 2)
			ra(a);
		if ((*a)->index == 1 || (*a)->index == 2)
		{
			pb(a, b);
			size--;
		}
	}
	sort_three(a);
	if ((*b)->index == 1)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_small(t_pile **a, t_pile **b)
{
	t_pile	*size_a;

	(void)b;
	size_a = (*a);
	if (ft_lstsize(size_a) == 2)
		sa(a);
	if (ft_lstsize(size_a) == 3)
		sort_three(a);
	if (ft_lstsize(size_a) == 4)
		sort_four(a, b);
	if (ft_lstsize(size_a) == 5)
		sort_five(a, b);
}

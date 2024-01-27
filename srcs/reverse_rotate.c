/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:09:04 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/08 16:00:47 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a) : Décale d’une position vers le bas
// tous les élements de la pile a. Le dernier élément devient le premier.
// rrb (reverse rotate b) : Décale d’une position vers le bas
// tous les élements de la pile b. Le dernier élément devient le premier.
// rrr : rra et rrb en même temps.

void	rra(t_pile **a)
{
	t_pile	*loop;
	t_pile	*new_pile;
	t_pile	*size;

	size = (*a);
	if (ft_lstsize(size) < 2)
		return ;
	write(1, "rra\n", 4);
	loop = (*a);
	while (loop->next->next)
	{
		if (loop->next->next != NULL)
			loop = loop->next;
	}
	new_pile = loop->next;
	loop->next = NULL;
	new_pile->next = (*a);
	(*a) = new_pile;
}

void	rrb(t_pile **b)
{
	t_pile	*loop;
	t_pile	*new_pile;
	t_pile	*size;

	size = (*b);
	if (ft_lstsize(size) < 2)
		return ;
	write(1, "rrb\n", 4);
	loop = (*b);
	while (loop->next->next)
	{
		if (loop->next->next != NULL)
			loop = loop->next;
	}
	new_pile = loop->next;
	loop->next = NULL;
	new_pile->next = (*b);
	(*b) = new_pile;
}

void	rra_no_print(t_pile **a)
{
	t_pile	*loop;
	t_pile	*new_pile;
	t_pile	*size;

	size = (*a);
	if (ft_lstsize(size) < 2)
		return ;
	loop = (*a);
	while (loop->next->next)
	{
		if (loop->next->next != NULL)
			loop = loop->next;
	}
	new_pile = loop->next;
	loop->next = NULL;
	new_pile->next = (*a);
	(*a) = new_pile;
}

void	rrb_no_print(t_pile **b)
{
	t_pile	*loop;
	t_pile	*new_pile;
	t_pile	*size;

	size = (*b);
	if (ft_lstsize(size) < 2)
		return ;
	loop = (*b);
	while (loop->next->next)
	{
		if (loop->next->next != NULL)
			loop = loop->next;
	}
	new_pile = loop->next;
	loop->next = NULL;
	new_pile->next = (*b);
	(*b) = new_pile;
}

void	rrr(t_pile **a, t_pile **b)
{
	t_pile	*size_a;
	t_pile	*size_b;

	size_a = (*a);
	size_b = (*b);
	if (ft_lstsize(size_a) >= 2 && ft_lstsize(size_b) >= 2)
	{
		write(1, "rrr\n", 4);
		rra_no_print(a);
		rrb_no_print(b);
	}
	else
	{
		rra(a);
		rrb(b);
	}
}

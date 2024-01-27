/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:07:04 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/08 15:34:16 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// ss : sa et sb en même temps.

void	sa(t_pile **a)
{
	t_pile	*old_first;
	t_pile	*old_second;
	t_pile	*size;

	size = (*a);
	if (ft_lstsize(size) < 2)
		return ;
	write(1, "sa\n", 3);
	old_first = (*a);
	old_second = (*a)->next;
	old_first->next = old_second->next;
	old_second->next = old_first;
	*a = old_second;
}

void	sb(t_pile **b)
{
	t_pile	*old_first;
	t_pile	*old_second;
	t_pile	*size;

	size = *b;
	if (ft_lstsize(size) < 2)
		return ;
	write(1, "sb\n", 3);
	old_first = (*b);
	old_second = (*b)->next;
	old_first->next = old_second->next;
	old_second->next = old_first;
	*b = old_second;
}

void	sa_no_print(t_pile **a)
{
	t_pile	*old_first;
	t_pile	*old_second;
	t_pile	*size;

	size = (*a);
	if (ft_lstsize(size) < 2)
		return ;
	old_first = (*a);
	old_second = (*a)->next;
	old_first->next = old_second->next;
	old_second->next = old_first;
	*a = old_second;
}

void	sb_no_print(t_pile **b)
{
	t_pile	*old_first;
	t_pile	*old_second;
	t_pile	*size;

	size = *b;
	if (ft_lstsize(size) < 2)
		return ;
	old_first = (*b);
	old_second = (*b)->next;
	old_first->next = old_second->next;
	old_second->next = old_first;
	*b = old_second;
}

void	ss(t_pile **a, t_pile **b)
{
	t_pile	*size_a;
	t_pile	*size_b;

	size_a = (*a);
	size_b = (*b);
	if (ft_lstsize(size_a) >= 2 && ft_lstsize(size_b) >= 2)
	{
		write(1, "ss\n", 3);
		sa_no_print(a);
		sb_no_print(b);
	}
	else
	{
		sa(a);
		sb(b);
	}
}

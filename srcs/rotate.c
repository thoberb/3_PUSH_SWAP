/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:07:50 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/08 16:00:35 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a) : Décale d’une position vers le haut
// tous les élements de la pile a.
// Le premier élément devient le dernier.
// rb (rotate b) : Décale d’une position vers le haut
// tous les élements de la pile b.
// Le premier élément devient le dernier.
// rr : ra et rb en même temps.

void	ra(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*loop;
	t_pile	*tmp_size;

	tmp_size = (*a);
	if (ft_lstsize(tmp_size) < 2)
		return ;
	write(1, "ra\n", 3);
	tmp = (*a);
	loop = (*a);
	(*a) = (*a)->next;
	while (loop->next)
	{
		if (loop->next != NULL)
			loop = loop->next;
	}
	loop->next = tmp;
	loop->next->next = NULL;
}

void	rb(t_pile **b)
{
	t_pile	*tmp;
	t_pile	*loop;
	t_pile	*tmp_size;

	tmp_size = (*b);
	if (ft_lstsize(tmp_size) < 2)
		return ;
	write(1, "rb\n", 3);
	tmp = (*b);
	loop = (*b);
	(*b) = (*b)->next;
	while (loop->next)
	{
		if (loop->next != NULL)
			loop = loop->next;
	}
	loop->next = tmp;
	loop->next->next = NULL;
}

void	ra_no_print(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*loop;
	t_pile	*tmp_size;

	tmp_size = (*a);
	if (ft_lstsize(tmp_size) < 2)
		return ;
	tmp = (*a);
	loop = (*a);
	(*a) = (*a)->next;
	while (loop->next)
	{
		if (loop->next != NULL)
			loop = loop->next;
	}
	loop->next = tmp;
	loop->next->next = NULL;
}

void	rb_no_print(t_pile **b)
{
	t_pile	*tmp;
	t_pile	*loop;
	t_pile	*tmp_size;

	tmp_size = (*b);
	if (ft_lstsize(tmp_size) < 2)
		return ;
	tmp = (*b);
	loop = (*b);
	(*b) = (*b)->next;
	while (loop->next)
	{
		if (loop->next != NULL)
			loop = loop->next;
	}
	loop->next = tmp;
	loop->next->next = NULL;
}

void	rr(t_pile **a, t_pile **b)
{
	t_pile	*size_a;
	t_pile	*size_b;

	size_a = (*a);
	size_b = (*b);
	if (ft_lstsize(size_a) >= 2 && ft_lstsize(size_b) >= 2)
	{
		write(1, "rr\n", 3);
		ra_no_print(a);
		rb_no_print(b);
	}
	else
	{
		ra(a);
		rb(b);
	}
}

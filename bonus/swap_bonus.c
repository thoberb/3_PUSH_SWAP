/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:30:48 by blandineber       #+#    #+#             */
/*   Updated: 2023/04/04 13:37:06 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	sa(t_infos *piles)
{
	t_pile	*tmp_a_1;
	t_pile	*tmp_a_2;
	t_pile	*tmp_a_3;

	if (!piles->a || !piles->a->next)
		return (0);
	tmp_a_1 = piles->a;
	tmp_a_2 = piles->a->next;
	tmp_a_3 = tmp_a_2->next;
	if (tmp_a_3)
		tmp_a_3->prev = tmp_a_1;
	tmp_a_1->next = tmp_a_3;
	tmp_a_1->prev = tmp_a_2;
	tmp_a_2->next = tmp_a_1;
	tmp_a_2->prev = NULL;
	piles->a = tmp_a_2;
	return (1);
}

int	sb(t_infos *piles)
{
	t_pile	*tmp_b_1;
	t_pile	*tmp_b_2;
	t_pile	*tmp_b_3;

	if (!piles->b || !piles->b->next)
		return (0);
	tmp_b_1 = piles->b;
	tmp_b_2 = piles->b->next;
	tmp_b_3 = tmp_b_2->next;
	if (tmp_b_3)
		tmp_b_3->prev = tmp_b_1;
	tmp_b_1->next = tmp_b_2->next;
	tmp_b_1->prev = tmp_b_2;
	tmp_b_2->next = tmp_b_1;
	tmp_b_2->prev = NULL;
	piles->b = tmp_b_2;
	return (1);
}

int	ss(t_infos *piles)
{
	if (piles->a && piles->a->next)
		sa(piles);
	if (piles->b && piles->b->next)
		sb(piles);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:10 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:40:19 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	pa(t_infos *piles)
{
	t_pile	*tmp_b;

	if (!piles->b)
		return (0);
	tmp_b = piles->b;
	if (tmp_b->next)
	{
		piles->b = tmp_b->next;
		piles->b->prev = NULL;
	}
	else
		piles->b = NULL;
	tmp_b->next = piles->a;
	if (tmp_b->next)
		piles->a->prev = tmp_b;
	piles->a = tmp_b;
	piles->size_a++;
	piles->size_b--;
	return (1);
}

int	pb(t_infos *piles)
{
	t_pile	*tmp_a;

	if (!piles->a)
		return (0);
	tmp_a = piles->a;
	if (tmp_a->next)
	{
		piles->a = tmp_a->next;
		piles->a->prev = NULL;
	}
	else
		piles->a = NULL;
	tmp_a->next = piles->b;
	if (tmp_a->next)
		piles->b->prev = tmp_a;
	piles->b = tmp_a;
	piles->size_a--;
	piles->size_b++;
	return (1);
}

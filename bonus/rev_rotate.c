/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:03 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:46:42 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	rra(t_infos *piles)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!piles->a || !piles->a->next)
		return (0);
	tmp = ft_lstlast(piles->a);
	last = tmp->prev;
	last->next = NULL;
	piles->a->prev = tmp;
	tmp->next = piles->a;
	tmp->prev = NULL;
	piles->a = tmp;
	return (1);
}

int	rrb(t_infos *piles)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!piles->b || !piles->b->next)
		return (0);
	tmp = ft_lstlast(piles->b);
	last = tmp->prev;
	last->next = NULL;
	piles->b->prev = tmp;
	tmp->next = piles->b;
	tmp->prev = NULL;
	piles->b = tmp;
	return (1);
}

int	rrr(t_infos *piles)
{
	if (piles->a && piles->a->next)
		rra(piles);
	if (piles->b && piles->b->next)
		rrb(piles);
	return (1);
}

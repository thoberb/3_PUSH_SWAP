/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:30:57 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:40:52 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ra(t_infos *piles)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!piles->a || !piles->a->next)
		return (0);
	tmp = piles->a;
	piles->a = tmp->next;
	piles->a->prev = NULL;
	tmp->next = NULL;
	last = ft_lstlast(piles->a);
	last->next = tmp;
	tmp->prev = last;
	return (1);
}

int	rb(t_infos *piles)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!piles->b || !piles->b->next)
		return (0);
	tmp = piles->b;
	piles->b = tmp->next;
	piles->b->prev = NULL;
	tmp->next = NULL;
	last = ft_lstlast(piles->b);
	last->next = tmp;
	tmp->prev = last;
	return (1);
}

int	rr(t_infos *piles)
{
	if (piles->a && piles->a->next)
		ra(piles);
	if (piles->b && piles->b->next)
		rb(piles);
	return (1);
}

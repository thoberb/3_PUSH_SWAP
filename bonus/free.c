/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:44 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:39:20 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_free_piles(t_infos *piles)
{
	if (!piles)
		return ;
	else
	{
		if (piles->a)
			ft_free_element(piles->a);
		if (piles->b)
			ft_free_element(piles->b);
		if (piles->tab)
			free(piles->tab);
		return (free(piles));
	}
}

void	ft_free_element(t_pile *lst)
{
	t_pile	*tmp;

	if (lst)
	{
		while (lst)
		{
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
	}
}

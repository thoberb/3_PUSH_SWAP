/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:52 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:32:30 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ft_exec(t_infos *piles)
{
	char	*mouv;
	int		r;

	mouv = "Salut";
	while (mouv)
	{
		mouv = get_next_line(0);
		if (mouv)
		{
			r = ft_exec_cmd(piles, mouv);
			free(mouv);
			if (!r)
				return (0);
		}
	}
	return (1);
}

int	ft_exec_cmd(t_infos *piles, char *mouv)
{
	if (ft_cmp(mouv, "sa\n"))
		sa(piles);
	else if (ft_cmp(mouv, "sb\n"))
		sb(piles);
	else if (ft_cmp(mouv, "ss\n"))
		ss(piles);
	else if (ft_cmp(mouv, "pa\n"))
		pa(piles);
	else if (ft_cmp(mouv, "pb\n"))
		pb(piles);
	else if (ft_cmp(mouv, "ra\n"))
		ra(piles);
	else if (ft_cmp(mouv, "rb\n"))
		rb(piles);
	else if (ft_cmp(mouv, "rr\n"))
		rr(piles);
	else if (ft_cmp(mouv, "rra\n"))
		rra(piles);
	else if (ft_cmp(mouv, "rrb\n"))
		rrb(piles);
	else if (ft_cmp(mouv, "rrr\n"))
		rrr(piles);
	else
		return (0);
	return (1);
}

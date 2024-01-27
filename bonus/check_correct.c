/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:30:38 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:51:33 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	correct(t_pile *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		else
			lst = lst->next;
	}
	return (1);
}

int	parse(char **argv, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_isnbr(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_piles(t_infos *piles)
{
	if (piles->b)
		return (write(1, "KO\n", 3), 0);
	if (!correct(piles->a))
		return (write(1, "KO\n", 3), 0);
	return (write(1, "OK\n", 3), 1);
}

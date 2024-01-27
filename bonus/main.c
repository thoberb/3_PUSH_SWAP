/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:18 by blandineber       #+#    #+#             */
/*   Updated: 2023/03/30 18:35:41 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_infos	*piles;

	piles = NULL;
	if (argc <= 2)
	{
		if (argc == 2 && !ft_isnbr(argv[1]))
			return (write(2, "Error\n", 6), 1);
		return (0);
	}
	else
	{
		piles = init(argc - 1, argv + 1);
		if (!piles)
			return (1);
	}
	if (!ft_exec(piles))
		return (ft_free_piles(piles), write(2, "Error\n", 6), 1);
	if (!ft_check_piles(piles))
		return (ft_free_piles(piles), 1);
	ft_free_piles(piles);
	return (0);
}

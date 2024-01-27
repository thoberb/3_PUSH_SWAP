/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:31:24 by blandineber       #+#    #+#             */
/*   Updated: 2023/04/01 14:55:35 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_infos	*init(int len, char **argv)
{
	t_infos	*piles;

	piles = malloc(sizeof(*piles));
	if (!piles)
		return (write(2, "Error\n", 6), NULL);
	if (parse(argv, len))
	{
		piles->a = NULL;
		piles->b = NULL;
		piles->tab = create_tab(argv, len);
		if (!piles->tab)
			return (ft_free_piles(piles), write(2, "Error\n", 6), NULL);
		piles->a = init_data(argv, len, piles->tab);
		if (!piles->a)
			return (ft_free_piles(piles), write(2, "Error\n", 6), NULL);
		piles->size = len;
		piles->size_a = piles->size;
		piles->size_b = 0;
	}
	else
		return (free(piles), write(2, "Error\n", 6), NULL);
	return (piles);
}

t_pile	*init_data(char **argv, int len, int *tab)
{
	t_pile	*list;
	t_pile	*new;
	int		i;

	i = 0;
	list = ft_lstnew(ft_atoi(argv[i]), tab, len);
	if (!list)
		return (NULL);
	i++;
	while (i < len)
	{
		new = ft_lstadd_back(list, ft_atoi(argv[i]), tab, len);
		if (!new)
			return (NULL);
		i++;
	}
	return (list);
}

int	*create_tab(char **argv, int len)
{
	int	*tab;
	int	i;
	int	success;

	i = 0;
	tab = malloc(sizeof(*tab) * len);
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	success = sort_tab(tab, len);
	if (!success)
		return (free(tab), NULL);
	return (tab);
}

int	sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			else if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

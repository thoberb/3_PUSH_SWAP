/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:34:55 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/15 16:44:28 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_pile **a, int *tab, int size)
{
	int		i;
	t_pile	*tmp_a;

	i = 0;
	tmp_a = (*a);
	while (tmp_a)
	{
		while (i < size)
		{
			if (tmp_a->nbr == tab[i])
				tmp_a->index = i + 1;
			i++;
		}
		i = 0;
		tmp_a = tmp_a->next;
	}
	free(tab);
}

void	sort_tab(t_pile **a, int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	(void)a;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] < tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	put_index(a, tab, size);
}

void	put_lst_in_tab(t_pile **a, int size)
{
	int		*tab;
	int		i;
	t_pile	*tmp_a;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		exit(1);
	tmp_a = (*a);
	i = 0;
	while (tmp_a->next)
	{
		tab[i] = tmp_a->nbr;
		tmp_a = tmp_a->next;
		i++;
	}
	tab[i] = tmp_a->nbr;
	sort_tab (a, tab, size);
}

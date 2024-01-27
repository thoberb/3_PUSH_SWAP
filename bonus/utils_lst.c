/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:30:31 by blandineber       #+#    #+#             */
/*   Updated: 2023/04/01 14:55:53 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_pile	*ft_lstnew(int nombre, int *tab, int len)
{
	t_pile	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nbr = nombre;
	while (i < len)
	{
		if (tab[i] == nombre)
			new->index = i + 1;
		i++;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_pile	*ft_lstadd_back(t_pile *lst, int nombre, int *tab, int len)
{
	t_pile	*tmp;
	t_pile	*new;

	new = NULL;
	if (lst)
	{
		tmp = ft_lstlast(lst);
		new = ft_lstnew(nombre, tab, len);
		if (!new || !tmp)
			return (free(tmp), free(new), NULL);
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
}

t_pile	*ft_lstlast(t_pile *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

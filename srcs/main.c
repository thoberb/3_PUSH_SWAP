/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:16:22 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/30 13:58:03 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//bonus chelou

#include "push_swap.h"

int	a_is_sorted(t_pile **a)
{
	t_pile	*check_a;

	check_a = (*a);
	while (check_a->next)
	{
		if (check_a->nbr < check_a->next->nbr)
			check_a = check_a->next;
		else
			return (0);
	}
	return (1);
}

void	init_pile(t_pile **a, char **argv)
{
	int	i;

	i = 1;
	(*a) = ft_lstnew(ft_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	ft_free(t_pile **a, t_pile **b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;

	while (*a)
	{
		tmp_a = (*a)->next;
		free(*a);
		(*a) = tmp_a;
	}
	while (*b)
	{
		tmp_b = (*b)->next;
		free(*b);
		(*b) = tmp_b;
	}
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (check_error(argc, argv) == 1)
		return (write(2, "Error\n", 6));
	init_pile(&a, argv);
	if (a_is_sorted(&a) == 1)
		return (ft_free(&a, &b), 0);
	if (ft_lstsize(a) <= 5)
		sort_small(&a, &b);
	else
		sort_big(&a, &b);
	ft_free(&a, &b);
}

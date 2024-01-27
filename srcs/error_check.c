/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:41:29 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/30 13:56:00 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max(int argc, char **argv)
{
	int		i;
	long	val;
	char	*end;

	i = 1;
	while (i < argc)
	{
		val = strtol(argv[i], &end, 10);
		if (*end != '\0')
			return (1);
		if (val > INT_MAX || val < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_doubles(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(int argc, char **argv)
{
	int		i;
	char	*p;

	i = 1;
	while (i <= argc - 1)
	{
		p = argv[i];
		while (*p)
		{
			if (!ft_isdigit(*p) && *p != '-' && *p != '+')
				return (1);
			p++;
		}
		i++;
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	if (check_int(argc, argv) == 1 || check_max(argc, argv) == 1
		|| check_doubles(argc, argv) == 1)
		return (1);
	return (0);
}

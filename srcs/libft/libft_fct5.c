/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fct5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blandineberthod <blandineberthod@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:45:21 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/30 13:47:16 by blandineber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	num_hexa_len(long long int nbr)
{
	long int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

void	ft_print_base_l(unsigned long long int nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar_fd(base[nbr], 1);
	else
	{
		ft_print_base_l(nbr / 16);
		ft_putchar_fd(base[nbr % 16], 1);
	}
}

int	ft_putnbr_base_low(unsigned long long int nbr)
{
	ft_print_base_l(nbr);
	return (num_hexa_len(nbr));
}

void	ft_print_base_u(unsigned long long int nbr)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar_fd(base[nbr], 1);
	else
	{
		ft_print_base_u(nbr / 16);
		ft_putchar_fd(base[nbr % 16], 1);
	}
}

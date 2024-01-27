/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fct6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:45:31 by bberthod          #+#    #+#             */
/*   Updated: 2023/02/20 18:00:02 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr_base_up(unsigned long long int nbr)
{
	ft_print_base_u(nbr);
	return (num_hexa_len(nbr));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	if (i != 0)
		write(fd, s, i);
	return (i);
}

int	u_num_hexa_len(unsigned long long int nbr)
{
	long int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

void	ft_putptr_hexa(unsigned long long int ptr)
{
	if (ptr >= 16)
	{
		ft_putptr_hexa(ptr / 16);
		ft_putptr_hexa(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
		{
			ft_putchar_fd(ptr - 10 + 'a', 1);
		}
	}
}

int	ft_putptr(unsigned long long int ptr)
{
	int	res;

	res = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putptr_hexa(ptr);
	res = u_num_hexa_len(ptr) + 2;
	return (res);
}

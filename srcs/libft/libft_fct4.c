/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fct4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:42:33 by bberthod          #+#    #+#             */
/*   Updated: 2023/02/22 14:42:35 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_lstlast(t_pile *lst)
{
	t_pile	*last;

	if (!lst)
		return (0);
	last = lst;
	while (last->next)
	{
		if (last->next != NULL)
			last = last->next;
	}
	return (last);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	num_len(long int nbr)
{
	long int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd(int nbr, int fd)
{
	int	len;

	len = num_len(nbr);
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (nbr < 0 && nbr != -2147483648)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	return (len);
}

int	ft_putunbr(unsigned long long int nbr)
{
	int	len;

	len = num_len(nbr);
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', 1);
	}
	else
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	return (len);
}

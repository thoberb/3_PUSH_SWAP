/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:35:46 by bberthod          #+#    #+#             */
/*   Updated: 2023/02/20 17:36:02 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*skip_whitespace(const char *p)
{
	while (ft_isspace(*p))
		p++;
	return (p);
}

int	get_sign(const char **p)
{
	int	sign;

	sign = 1;
	if (**p == '-')
	{
		sign = -1;
		(*p)++;
	}
	else if (**p == '+')
		(*p)++;
	return (sign);
}

int	get_base(const char **p, int base)
{
	if (base == 0)
	{
		if (**p == '0')
		{
			base = 8;
			(*p)++;
		}
		if (ft_tolower(**p) == 'x')
		{
			base = 16;
			(*p)++;
		}
		else
			base = 10;
	}
	return (base);
}

long	parse_number(const char **p, int base)
{
	long	result;

	result = 0;
	while (ft_isdigit(**p)
		|| (**p >= 'a' && **p <= 'z' && **p - 'a' + 10 < base)
		|| (**p >= 'A' && **p <= 'Z' && **p - 'A' + 10 < base))
	{
		if (**p >= 'a' && **p <= 'z')
			result = result * base + (**p - 'a' + 10);
		else if (**p >= 'A' && **p <= 'Z')
			result = result * base + (**p - 'A' + 10);
		else
			result = result * base + (**p - '0');
		(*p)++;
	}
	return (result);
}

void	handle_overflow(long *result, int sign)
{
	if (*result * sign > LONG_MAX)
		*result = LONG_MAX;
	else if (*result * sign < LONG_MIN)
		*result = LONG_MIN;
}

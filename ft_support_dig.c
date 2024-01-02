/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_dig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terjimen <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:39:46 by terjimen          #+#    #+#             */
/*   Updated: 2024/01/02 13:05:42 by terjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_int(long n, int base)
{
	int		i;
	char	*dig;

	dig = "0123456789";
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_int(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(dig(n)));
	else
	{
		i = print_int(n / base, base);
		return (i + print_int(n % base, base));
	}
}

int	print_dig(unsigned int n, int base)
{
	int		i;
	char	*dig;

	dig = "0123456789";
	if (n < base)
		return (print_char(dig[n]));
	else
	{
		i = print_dig(n / base, base);
		return (i + print_dig(n % base, base));
	}
}

int	print_dig_alt(unsigned int n, int base)
{
	int		i;
	char	*dig;

	dig = "0123456789ABCDEF";
	if (n < base)
		return (print_char(dig[n]));
	else
	{
		i = print_dig_alt(n / base, base);
		return (i + print_dig_alt(n % base, base));
	}
}

int	print_unsigned_dec(unsigned int n, int base)
{
	int		i;
	char	*dig;

	dig = "0123456789";
	if (n < base)
		return (print_char(dig[n]));
	else
	{
		i = print_unsigned_dec(n / base, base);
		return (i + print_unsoigned_dec(n % base, base));
	}
}

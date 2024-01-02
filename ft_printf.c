/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terjimen <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:10:24 by terjimen          #+#    #+#             */
/*   Updated: 2024/01/02 13:27:02 by terjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_form(char specifier, va_list ap)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += print_char(va_arg(ap, int));
	else if (specifier == 's')
		i += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		i += print_int((long)va_arg(ap, int), 10, D_L_BASE);
	else if (specifier == 'x')
		i += print_dig((long)va_arg(ap, unsigned int), 16, H_L_BASE);
	else if (specifier == 'X')
		i += print_dig_alt((long)va_arg(ap, unsigned int), 16, H_U_BASE);
	else if (specifier == 'u')
		i += print_unsigned_dec((unsigned int)va_arg(ap, unsigned int), 10,
				D_L_BASE);
	else if (specifier == '%')
		return (write(1, "%", 1));
	else if (specifier == 'p')
		i += print_mem((unsigned long)va_arg(ap, void *), 16, H_L_BASE);
	return (i);
}

int	ft_printf(char const *form, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	while (*form)
	{
		if (form == '%')
			i += print_form(*(++form), ap);
		else
			i += write (1, form, 1);
		form++;
	}
	va_end(ap);
	return (i);
}

/*int	main(void)
{
	int	i;

	i = ft_printf("Testeo de función");
	ft_printf("Se ha escrito esto %d\n", i);
	return (0);
}
*/

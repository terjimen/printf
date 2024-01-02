/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terjimen <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:28:20 by terjimen          #+#    #+#             */
/*   Updated: 2024/01/02 13:29:52 by terjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		print_char((int)*str);
		i++;
		str++;
	}
	return (i);
}

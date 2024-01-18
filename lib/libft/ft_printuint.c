/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:02:33 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 11:59:16 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long number)
{
	int	i;

	i = 1;
	while (number >= 10)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

int	ft_printuint(unsigned int number)
{
	long	long_number;
	int		printed_chars;
	long	aux;

	aux = 0;
	printed_chars = 1;
	long_number = (long)number;
	if (long_number < 0)
		long_number = 4294967295 + long_number;
	aux = long_number;
	if (long_number > 9)
	{
		ft_printuint((unsigned int)(long_number / 10));
		ft_putchar(long_number % 10 + '0');
	}
	else
		ft_putchar(long_number + '0');
	printed_chars = ft_count(aux);
	return (printed_chars);
}

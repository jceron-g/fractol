/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:39:02 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 11:59:58 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sethex(unsigned long number, char *base, int printed_chars)
{
	if (number > 15)
	{
		printed_chars = ft_sethex(number / 16, base, printed_chars);
		write (1, &(base[number % 16]), 1);
		printed_chars++;
	}
	else
	{
		write (1, &(base[number]), 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_puthex(unsigned long i, char c)
{
	char	*lower_base;
	char	*upper_base;
	int		printed_chars;

	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	printed_chars = 0;
	if (c == 'X')
		printed_chars = ft_sethex((unsigned int)i, upper_base, printed_chars);
	else if (c == 'x')
		printed_chars = ft_sethex((unsigned int)i, lower_base, printed_chars);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		printed_chars = ft_sethex(i, lower_base, printed_chars);
		printed_chars += 2;
	}
	return (printed_chars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:50:52 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 11:59:41 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putdec(int number)
{
	int	aux;

	aux = 0;
	if (number == -2147483648)
	{
		aux += ft_putchar('-');
		aux += ft_putchar('2');
		aux += ft_putdec(147483648);
	}
	else if (number > 9)
	{
		aux += ft_putdec(number / 10);
		aux += ft_putdec(number % 10);
	}
	else if (number < 0)
	{
		aux += ft_putchar('-');
		aux += ft_putdec(-number);
	}
	else
		aux += ft_putchar(number + '0');
	return (aux);
}

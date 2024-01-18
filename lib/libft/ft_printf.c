/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:45:44 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 11:17:19 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(char const *str, va_list ap)
{
	int	i;
	int	printed_chars;

	i = 0;
	printed_chars = 0;
	if (str[i] == '%')
		printed_chars += ft_putchar('%');
	else if (str[i] == 'c')
		printed_chars += ft_putchar(va_arg(ap, int));
	else if (str[i] == 's')
		printed_chars += ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		printed_chars += ft_putdec(va_arg(ap, int));
	else if (str[i] == 'u')
		printed_chars = ft_printuint(va_arg(ap, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		printed_chars += ft_puthex(va_arg(ap, unsigned long), str[i]);
	else if (str[i] == 'p')
		printed_chars += ft_puthex(va_arg(ap, unsigned long), str[i]);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	va_start(ap, format);
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += ft_print_format(&format[i], ap);
		}
		else
			printed_chars += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (printed_chars);
}

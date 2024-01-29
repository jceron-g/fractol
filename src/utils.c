/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:33:07 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/29 12:04:51 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double num, double n_min, double n_max, double o_max)
{
	double	o_min;
	double	result;

	o_min = 0.0;
	result = ((n_max - n_min) * (num - o_min) / (o_max - o_min) + n_min);
	return (result);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imag = z1.imag + z2.imag;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imag * z.imag);
	result.imag = 2 * z.real * z.imag;
	return (result);
}

void	msg_error(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot or\n", 2);
	ft_putstr_fd("./fractol julia <constant_real> <constant_imaginary>\n", 2);
	exit(EXIT_FAILURE);
}


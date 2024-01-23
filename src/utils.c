/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:33:07 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/23 12:11:27 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double num, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * (num) / (o_max) + n_min);
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

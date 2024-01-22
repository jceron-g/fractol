/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:33:07 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/22 13:20:06 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double unscale_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscale_num) / (old_max) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}

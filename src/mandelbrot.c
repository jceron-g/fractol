/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/23 11:21:24 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->esc_value = 4;
	fractal->iteration_def = 100;
}

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, fractal->name, true);
	if (!fractal->mlx_connection)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
	fractal->max_iters = 100;
	fractal->max_real = 2;
	fractal->min_real = -2;
	fractal->max_imaginary = 2;
	fractal->min_imaginary = -2;
}

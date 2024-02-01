/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/02/01 13:10:21 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->esc_value = 4;
	fractal->iteration_def = 60;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
}

void	msg_error(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	ft_putstr_fd("Please use: ./fractol mandelbrot or\n", 2);
	ft_putstr_fd("./fractol julia <constant_real> <constant_imaginary>\n", 2);
	exit(EXIT_FAILURE);
}

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (!fractal->mlx_connection)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
	data_init(fractal);
}

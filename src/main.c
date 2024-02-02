/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:34:53 by jceron-g          #+#    #+#             */
/*   Updated: 2024/02/02 11:51:35 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (check_fractal(argc, argv, &fractal) == 0)
		return (EXIT_FAILURE);
	init_mandelbrot(&fractal);
	mlx_key_hook(fractal.mlx_connection, &my_keyhook, &fractal);
	mlx_scroll_hook(fractal.mlx_connection, &ft_scrollhook, &fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	mlx_terminate(fractal.mlx_connection);
	return (EXIT_SUCCESS);

}

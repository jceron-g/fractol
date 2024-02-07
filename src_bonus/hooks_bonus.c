/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:00:52 by jceron-g          #+#    #+#             */
/*   Updated: 2024/02/06 16:20:17 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	(void)keydata;
	if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx_connection);
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_KP_ADD))
		fractal->iteration_def += 10;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_KP_SUBTRACT))
		fractal->iteration_def -= 10;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_UP))
		fractal->shift_y += 0.5;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_DOWN))
		fractal->shift_y -= 0.5;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_RIGHT))
		fractal->shift_x += 0.5;
	else if (mlx_is_key_down(fractal->mlx_connection, MLX_KEY_LEFT))
		fractal->shift_x -= 0.5;
	fractal_render(fractal);
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = param;
	xdelta = 0;
	mlx_get_mouse_pos(fractal->mlx_connection, &x, &y);
	if (ydelta > 0)
	{
		fractal->min_real += (fractal->shift_x * WIDTH * fractal->zoom \
		* ((double)x / WIDTH));
		fractal->max_imag -= (fractal->shift_y * HEIGHT * fractal->zoom \
		* ((double)y / WIDTH));
	}
	else if (ydelta < 0)
	{
		fractal->min_real -= (fractal->shift_x * WIDTH * fractal->zoom \
		* ((double)x / WIDTH));
		fractal->max_imag += (fractal->shift_y * HEIGHT * fractal->zoom \
		* ((double)y / WIDTH));
	}
	fractal_render(fractal);
}

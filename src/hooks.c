/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:00:52 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/29 12:11:38 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx_connection);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->shift_y += 0.5;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->shift_y -= 0.5;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->shift_x += 0.5;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->shift_x -= 0.5;
	fractal_render(fractal);
}

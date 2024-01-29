/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:35:33 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/29 13:48:46 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_pixel(int pixel_x, int pixel_y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = 0.0;
	z.imag = 0.0;
	c.real = map(pixel_x, -2, 2, WIDTH) + fractal->shift_x;
	c.imag = map(pixel_y, 2, -2, HEIGHT) + fractal->shift_y;
	while (i < fractal->iteration_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > fractal->esc_value)
		{
			color = map(i, BLACK, WHITE, fractal->iteration_def);
			mlx_put_pixel(fractal->img, pixel_x, pixel_y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, pixel_x, pixel_y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = 0;
	while (pixel_y < HEIGHT)
	{
		pixel_x = 0;
		while (pixel_x < WIDTH)
		{
			handle_pixel(pixel_x, pixel_y, fractal);
			pixel_x++;
		}
		pixel_y++;
	}
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}

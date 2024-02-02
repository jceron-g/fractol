/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:35:33 by jceron-g          #+#    #+#             */
/*   Updated: 2024/02/02 11:32:33 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	choose_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->imag = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->imag = z->imag;
	}
}

void	handle_pixel(int pixel_x, int pixel_y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (map(pixel_x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.imag = (map(pixel_y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	choose_fractal(&z, &c, fractal);
	while (i < fractal->iteration_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > fractal->esc_value)
		{
			color = map(i, BLACK, PURPLE, fractal->iteration_def);
			mlx_put_pixel(fractal->img, pixel_x, pixel_y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, pixel_x, pixel_y, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = 0;
	pixel_x = 0;
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

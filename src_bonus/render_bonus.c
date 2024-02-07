/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:35:33 by jceron-g          #+#    #+#             */
/*   Updated: 2024/02/06 15:56:01 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	choose_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->ima = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->ima = z->ima;
	}
}

void	handle_pixel(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (map(fractal->x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.ima = (map(fractal->y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	choose_fractal(&z, &c, fractal);
	while (i < fractal->iteration_def)
	{
		z = sum_complex(square_complex(z, fractal), c, fractal);
		if ((z.real * z.real) + (z.ima * z.ima) > fractal->esc_value)
		{
			color = map(i, BLACK, RED, fractal->iteration_def);
			mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractal->img, fractal->x, fractal->y, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	fractal->y = 0;
	fractal->x = 0;
	while (fractal->y < HEIGHT)
	{
		fractal->x = 0;
		while (fractal->x < WIDTH)
		{
			handle_pixel(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_image_to_window(fractal->mlx_connection, fractal->img, 0, 0);
}

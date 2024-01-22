/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/22 13:09:09 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/* INIT
 * MLX
 * LISTENING EVENTS
 * HOOKS DATA
*/
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

void	handle_pixel(int pixel_x, int pixel_y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	//1 iteracion
	z.real = 0.0;
	z.imaginary = 0.0;
	//pixel coordinate x && y scaled to fit mandelbrot
	c.real = map(pixel_x, -2, 2, WIDTH);
	c.imaginary = map(pixel_y, 2, -2, HEIGHT);
	/*Now we use a while to see how many times do i want to iterate
	and check if the point has scaped QUICK MATHS*/
	
}

void	fractal_render(t_fractal *fractal)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = 0;
	while (pixel_y < HEIGHT)
	{
		pixel_y++;
		pixel_x = 0;
		while (pixel_x < WIDTH)
		{
			handle_pixel(pixel_x, pixel_y, fractal);
		}
	}
}

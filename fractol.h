/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:21 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/26 11:19:51 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# define WIDTH 800
# define HEIGHT 800
// Definición de colores en formato hexadecimal ARGB
# define BLACK       0x000000FF
# define WHITE       0xFFFFFFFF
# define RED         0xFF0000FF
# define GREEN       0x00FF00FF
# define BLUE        0x0000FFFF
# define YELLOW      0xFFFF00FF
# define MAGENTA     0xFF00FFFF
# define CYAN        0x00FFFFFF
# define ORANGE      0xFFA500FF
# define PURPLE      0x800080FF
# define GRAY        0x808080FF
# define LIGHT_GRAY  0xD3D3D3FF
# define DARK_GRAY   0xA9A9A9FF

typedef struct s_complex
{
	double	real;
	double	imag;
}				t_complex;
/*FRACTAL ID*/
typedef struct s_fractal
{
	//MLX
	char		*name;
	mlx_t		*mlx_connection; //mlx_init()
	void		*mlx_window;	//mlx_new_window()
	//IMAGE
	mlx_image_t	*img;
	//NUMBER BOUNDARIES
	int			max_iters;
	int			max_real;
	int			max_imaginary;
	int			min_real;
	int			min_imaginary;
	void		*colors;
	double		esc_value;		//hypotenuse
	int			iteration_def;
}				t_fractal;
/*Display functions*/
void		init_mandelbrot(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int pixel_x, int pixel_y, t_fractal *fractal);
/*Maths arreglar map*/
double		map(double num, double n_min, double n_max, double o_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		data_init(t_fractal *fractal);
/*HOOKS*/
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);

#endif
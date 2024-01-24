/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:21 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/24 12:07:54 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# define WIDTH 1200
# define HEIGHT 800
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define LIME_SHOCK 0xCCFF00FF

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
	void		*mlx_connection; //mlx_init()
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

#endif
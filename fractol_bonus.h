/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:11:02 by jceron-g          #+#    #+#             */
/*   Updated: 2024/02/07 11:42:22 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
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
# define PURPLE      0x660066FF
# define GRAY        0x808080FF
# define LIGHT_GRAY  0xD3D3D3FF
# define DARK_GRAY   0xA9A9A9FF

typedef struct s_complex
{
	double	real;
	double	ima;
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
	void		*colors;
	double		esc_value;		//hypotenuse
	int			iteration_def;
	double		min_real;
	double		max_imag;
	double		shift_x;
	double		shift_y;
	double		julia_x;
	double		julia_y;
	double		zoom;
	double		x;
	double		y;
}				t_fractal;
/*Display functions*/
void		init_mandelbrot(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(t_fractal *fractal);
void		msg_error(void);
void		data_init(t_fractal *fractal);
void		choose_fractal(t_complex *z, t_complex *c, t_fractal *fractal);
int			check_fractal(int argc, char **argv, t_fractal *fractal);
int			check_type(int argc, char **argv, t_fractal *fractal);
void		check_params(char *str);
/*Maths*/
double		map(double num, double n_min, double n_max, double o_max);
t_complex	sum_complex(t_complex z1, t_complex z2, t_fractal *fractal);
t_complex	square_complex(t_complex z, t_fractal *fractal);
double		ft_atodbl(int i, double n, double t, char *str);
/*HOOKS*/
void		ft_scrollhook(double xdelta, double ydelta, void *param);
void		my_keyhook(mlx_key_data_t keydata, void *param);

#endif
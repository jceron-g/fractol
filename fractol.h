/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:21 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/19 13:14:58 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# define WIDTH 1200
# define HEIGHT 800

typedef struct s_complex
{
	double	real;
	double	i;
}				t_complex;
/*FRACTAL ID*/
typedef struct s_fractal
{
	//MLX
	char	*name;
	void	*mlx_connection; //mlx_init()
	void	*mlx_window;	//mlx_new_window()
	//IMAGE
	t_img	*img;
	//NUMBER BOUNDARIES
	int		max_iters;
	int		max_real;
	int		max_imaginary;
	int		min_real;
	int		min_imaginary;
}				t_fractal;

/* IMAGE This is basically a pixels buffer*/
typedef struct s_img
{
	void	*img_ptr; //pointer to img struct
	char	*pixels_ptr; //points to the actuals pixels
	int		bpp; //Bits per pixel
	int		endian; //How the order of bytes in a multi-byte value is perceived
	int		line_line; //We will use it further
}				t_img;

/* Color functions*/
int		get_rgba(int r, int g, int b, int a);

/*Display functions*/
void	init_mandelbrot(t_fractal *fractal);

#endif
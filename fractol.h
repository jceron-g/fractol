/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:21 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/17 12:44:12 by jceron-g         ###   ########.fr       */
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

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	void	*img;
}				t_fractal;
#endif
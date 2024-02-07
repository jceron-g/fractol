/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:33:07 by jceron-g          #+#    #+#             */
/*   Updated: 2024/02/07 11:41:28 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

double	map(double num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (num) / (old_max) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2, t_fractal *fractal)
{
	t_complex	result;

	if (!ft_strncmp(fractal->name, "burningship", 11))
	{
		result.real = z1.real + z2.real;
		result.ima = z1.ima - z2.ima;
	}
	else
	{
		result.real = z1.real + z2.real;
		result.ima = z1.ima + z2.ima;
	}
	return (result);
}

t_complex	square_complex(t_complex z, t_fractal *fractal)
{
	t_complex	result;

	if (!ft_strncmp(fractal->name, "burningship", 11))
	{
		result.real = (z.real * z.real) - (z.ima * z.ima);
		result.ima = 2 * fabs((z.real * z.ima));
	}
	else
	{
		result.real = (z.real * z.real) - (z.ima * z.ima);
		result.ima = 2 * (z.real * z.ima);
	}
	return (result);
}

double	ft_atodbl(int i, double n, double t, char *str)
{
	int	decimal;

	decimal = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			t = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '.')
			decimal = 1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (decimal == 1)
				t /= 10.00;
			n = (n * 10.00) + (str[i] - '0');
		}
		i++;
	}
	return (t * n);
}

int	check_type(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractal->name = argv[1];
	else if (argc == 2 && !ft_strncmp(argv[1], "burningship", 11))
		fractal->name = argv[1];
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		check_params(argv[2]);
		check_params(argv[3]);
		fractal->name = argv[1];
		fractal->julia_x = ft_atodbl(0.0, 0.0, 1.0, argv[2]);
		fractal->julia_y = ft_atodbl(0.0, 0.0, 1.0, argv[3]);
	}
	else
	{
		msg_error();
		return (0);
	}
	return (1);
}

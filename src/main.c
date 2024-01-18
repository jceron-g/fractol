/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:34:53 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/17 12:55:26 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// int main(int argc, char **argv)
// {
// 	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
// 	|| argc == 4 && !ft_strncmp(argv[1], "julia", 5))
// 	{
// 	}
// }
int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "hola", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_loop(mlx);
}

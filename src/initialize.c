/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:46 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/19 11:58:11 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/* INIT
 * MLX
 * LISTENING EVENTS
 * HOOKS DATA
*/
void	fractal_init(t_fractal *fractal)
{
//MLX STUFF
	fractal->mlx_connection = mlx_init();
	fractal->mlx_window = mlx_new_window()
}

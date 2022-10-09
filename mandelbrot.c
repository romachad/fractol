/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:33:17 by romachad          #+#    #+#             */
/*   Updated: 2022/10/09 08:15:36 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *f, int x, int y, double cr, double ci)
{
	int	n;
	double	zr;
	double	zi;
	double	tmp;
	int	flag;

	zr = 0;
	zi = 0;
	n = 0;
	flag = 1;
	while (n++ < MAX_ITER)
	{
		if ((zr * zr) + (zi * zi) > 4.0)
		{
			flag = 0;
			break ;
		}
		tmp = (2 * zr * zi) + ci;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = tmp;
	}
	if (flag == 1)
		mlx_pixel_put(f->mlx, f->win, x, y, 0);
	else
		mlx_pixel_put(f->mlx, f->win, x, y, 0xFFFFFF);
}

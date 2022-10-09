/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:33:17 by romachad          #+#    #+#             */
/*   Updated: 2022/10/09 19:41:06 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data-> bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
		my_mlx_pixel_put(f, x, y, 0x00000000);
	else
		my_mlx_pixel_put(f, x, y, 0x00FFFFFF);
}

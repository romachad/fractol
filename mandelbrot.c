/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:33:17 by romachad          #+#    #+#             */
/*   Updated: 2022/10/13 22:43:19 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr + (f->Y * f->line_length + f->X * (f-> bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*void my_mlx_pixel_put2(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr2 + (f->Y * f->line_length + f->X * (f-> bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

void	mandelbrot(t_fractol *f, double cr, double ci)
{
	int	n;
	double	zr;
	double	zi;
	double	tmp;
	int	flag;

	zr = 0;
	zi = 0;
	n = -1;
	flag = 1;
	while (++n < MAX_ITER)
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
		my_mlx_pixel_put(f, 0x00000000);
	else
		my_mlx_pixel_put(f, 0x00FFFFFF);
}

#include <stdio.h>
void	draw_change(t_fractol *f)
{
	double	cr;
	double	ci;

	f->Y = f->start_Y;
	while (++f->Y < HEIGHT)
	{
		f->X = f->start_X;
		while (++f->X < f->max_WIDTH)
		{
			cr = f->min_r + (((double)f->X * (f->max_r - f->min_r)) / WIDTH);
			ci = f->min_i + (((double)f->Y * (f->max_i - f->min_i)) / HEIGHT);
			mandelbrot2(f, cr, ci);
		}
	}
}
/*void	draw_change(t_fractol *f, int x, int y)
{
	double cr;
	double ci;

	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			cr = f->min_r + (((double)x * (f->max_r - f->min_r)) / WIDTH);
			ci = f->min_r + (((double)y * (f->max_i - f->min_i)) / HEIGHT);
			mandelbrot2(f, cr, ci);
			printf("TOMA NO CU!\n\n");
			x++;
		}
		y++;
	}
}*/

void	mandelbrot2(t_fractol *f, double cr, double ci)
{
	int	n;
	double	zr;
	double	zi;
	double	tmp;
	int	flag;

	zr = 0;
	zi = 0;
	n = -1;
	flag = 1;
	while (++n < MAX_ITER)
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
		my_mlx_pixel_put(f, 0x00FF0000);
	else
		my_mlx_pixel_put(f, 0x0000FFFF);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:33:17 by romachad          #+#    #+#             */
/*   Updated: 2022/11/06 06:02:56 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	draw_fractal(t_fractol *f)
{
	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		while (++f->x < WIDTH)
		{
			f->zr = f->min_r + (((double)f->x * \
						(f->max_r - f->min_r)) / WIDTH);
			f->zi = f->min_i + (((double)f->y * \
						(f->max_i - f->min_i)) / HEIGHT);
			if (f->fractol == 'n')
				newton(f);
			else
				fractal(f);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	my_mlx_pixel_put(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr + (f->y * f->line_length + f->x * (f-> bits_per_pixel / 8));
	if (f->n <= 10)
		color = first_color(f);
	if (f->n > 10 && f->n <= 20)
		color = second_color(f);
	if (f->n > 20 && f->n <= 30)
		color = third_color(f);
	if (f->n > 30 && f->n <= 40)
		color = fourth_color(f);
	if (f->n > 40 && f->n <= 50)
		color = fifth_color(f);
	if (f->n > 50 && f->n <= 60)
		color = sixth_color(f);
	if (f->n > 60 && f->n <= 70)
		color = seventh_color(f);
	if (f->n > 70 && f->n < 80)
		color = eighth_color(f);
	*(unsigned int *)dst = color;
}

void	fractal(t_fractol *f)
{
	if (f->fractol == 'm')
	{
		f->cr = f->zr;
		f->ci = f->zi;
		f->zr = 0;
		f->zi = 0;
	}
	f->n = -1;
	while (++f->n < MAX_ITER)
	{
		if ((f->zr * f->zr) + (f->zi * f->zi) > 4.0)
			break ;
		f->tmp = (2 * f->zr * f->zi) + f->ci;
		f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
		f->zi = f->tmp;
	}
	if (f->n == MAX_ITER)
		my_mlx_pixel_put(f, 0x00000000);
	else
		my_mlx_pixel_put(f, 0x000000FF);
}

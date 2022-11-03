
#include "../headers/fractol.h"

void	my_mlx_pixel_put_newton(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr + (f->y * f->line_length + f->x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//#include <stdio.h>
void	newton(t_fractol *f)
{
	double	tmpi;
	double	tmpr;
	double	denominator;

	f->n = -1;
	while (++f->n < 80)
	{
		denominator = 3 * (((f->zr * f->zr) + (f->zi * f->zi)) * ((f->zr * f->zr) + (f->zi * f->zi)));
		tmpi = (2 * f->zi * f->zi * f->zi * f->zi * f->zi) - (2 * f->zr * f->zi) + (4 * f->zr * f->zr * f->zi * f->zi * f->zi) + (2 * f->zr * f->zr * f->zr * f->zr * f->zi);
		tmpr = (2 * f->zr * f->zr * f->zr * f->zr * f->zr) + (f->zr * f->zr) - (f->zi * f->zi) + (4 * f->zr * f->zr * f->zr * f->zi * f->zi) + (2 * f->zr * f->zi * f->zi * f->zi * f->zi);
		f->zi = tmpi / denominator;
		f->zr = tmpr / denominator;
	}
	root_distance(f);
}

void	root_distance(t_fractol *f)
{
	double	dist_r0;
	double	dist_r1;
	double	dist_r2;
	double	dist_i;
	double	dist_r;

	dist_r = 1 - f->zr;
	dist_i = f->zi;
	dist_r0 = (dist_r * dist_r) + (dist_i * dist_i);
	dist_r = - f->zr - NEWTON_R2;
	dist_i = NEWTON_R3 - f->zi;
	dist_r1 = (dist_r * dist_r) + (dist_i * dist_i);
	dist_r = - f->zr - NEWTON_R2;
	dist_i = - f->zi - NEWTON_R3;
	dist_r2 = (dist_r * dist_r) + (dist_i * dist_i);
	if (dist_r0 < dist_r1 && dist_r0 < dist_r2)
		my_mlx_pixel_put_newton(f, 0x00FF0000);
	else if (dist_r1 < dist_r0 && dist_r1 < dist_r2)
		my_mlx_pixel_put_newton(f, 0x000000FF);
	else if (dist_r2 < dist_r0 && dist_r2 < dist_r1)
		my_mlx_pixel_put_newton(f, 0x0000FF00);
	else if (dist_r1 == dist_r2 && dist_r2 == dist_r0)
		my_mlx_pixel_put_newton(f, 0x00FFFF00);
	else
		my_mlx_pixel_put_newton(f, 0x00000000);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:44:33 by romachad          #+#    #+#             */
/*   Updated: 2022/10/09 08:15:41 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *f)
{
	int	x;
	int	y;
	double	cr;
	double	ci;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			cr = ((f->min_r + (double)x) * (f->max_r - f->min_r)) / WIDTH;
			ci = ((f->min_i + (double)y) * (f->max_i - f->min_i)) / HEIGHT;
			mandelbrot(f, x, y, pr, pi);
		}
	}
}

int	main(void)
{
	t_fractol	f;

	f.mlx = mlx_init();
	f.min_r = -2;
	f.max_r = 1;
	f.min_i = 1;
	f.max_i = f.min_i + (f.max_r - f.min_r) * (HEIGHT / WIDTH);
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Frac test");
	draw_fractal(&f);
	mlx_loop(f.mlx);
}

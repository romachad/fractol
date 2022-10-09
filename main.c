/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:44:33 by romachad          #+#    #+#             */
/*   Updated: 2022/10/09 19:40:33 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *f)
{
	int	x;
	int	y;
	double	cr;
	double	ci;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cr = f->min_r + (((double)x * (f->max_r - f->min_r)) / WIDTH);
			ci = f->min_i + (((double)y * (f->max_i - f->min_i)) / HEIGHT);
			mandelbrot(f, x, y, cr, ci);
			//x++;
		}
		//y++;
	}
}

int	main(void)
{
	t_fractol	f;

	f.mlx = mlx_init();
	f.min_r = -2;
	f.max_r = 1;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * (HEIGHT / WIDTH);
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Frac test");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bits_per_pixel, &f.line_length, &f.endian);
	draw_fractal(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_loop(f.mlx);
}

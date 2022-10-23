/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:44:33 by romachad          #+#    #+#             */
/*   Updated: 2022/10/23 03:37:22 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

#include <stdio.h>

void	set_mandelbrot(t_fractol *f)
{
	f->mlx = mlx_init();
	f->min_r = -2;
	f->max_r = 1;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
}

void	set_julia(t_fractol *f)
{
	f->mlx = mlx_init();
	f->min_r = -1.5;
	f->max_r = 1.5;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	f->cr = -0.54;
	f->ci = 0.54;
}

void	main_fractal(t_fractol *f)
{
	if (f->fractol == 'm')
		f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Mandelbrot");
	else
		f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Julia");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 6, 1L<<6, mouse_move, f);
	mlx_loop(f->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2)
	{
		printf("too much or too little args");
		exit(1);
	}
	if (argc == 2 && (argv[1][0] == 'm' || argv[1][0] == 'j'))
	{
		f.fractol = argv[1][0];
		if (f.fractol == 'm')
			set_mandelbrot(&f);
		else
			set_julia(&f);
		main_fractal(&f);
	}
	exit(0);
}

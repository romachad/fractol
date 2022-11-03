/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:44:33 by romachad          #+#    #+#             */
/*   Updated: 2022/11/03 20:30:36 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/ft_printf.h"

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
}

void	main_fractal(t_fractol *f)
{
	if (f->fractol == 'm')
		f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Mandelbrot");
	else if (f->fractol == 'j')
		f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Julia");
	else
		f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Newton");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, \
			&f->line_length, &f->endian);
	reset(f);
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 6, 1L << 6, mouse_move, f);
	mlx_hook(f->win, 17, 0, quit, f);
	mlx_expose_hook(f->win, expose, f);
	mlx_loop(f->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2 || argc > 4)
	{
		message();
		exit(0);
	}
	if (argv[1][0] == 'm' || argv[1][0] == 'j' || argv[1][0] == 'n')
	{
		f.fractol = argv[1][0];
		if (f.fractol == 'm')
			set_mandelbrot(&f);
		else
		{
			f.cr = ft_atof(argv[2]);
			f.ci = ft_atof(argv[3]);
			set_julia(&f);
		}
		main_fractal(&f);
	}
	else
		message();
	exit(0);
}

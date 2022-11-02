/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:44:33 by romachad          #+#    #+#             */
/*   Updated: 2022/11/02 04:42:34 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/ft_printf.h"

#include <stdio.h> //REMOVER!!!!

void	set_mandelbrot(t_fractol *f)
{
	f->mlx = mlx_init();
	/* Normal mandelbrot start */
	f->min_r = -2;
	f->max_r = 1;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	//f->zoom_lvl = 0;
	/* End of mandelbrot */

	/* Values for performance test */
	/*f->min_r = -1.511373;
	f->max_r = -1.511335;
	f->min_i = -0.000028;
	f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);*/
	/*End of performance test*/
}

void	set_julia(t_fractol *f)
{
	f->mlx = mlx_init();
	f->min_r = -1.5;
	f->max_r = 1.5;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	/*f->cr = -0.54;
	f->ci = 0.54;*/
	//f->zoom_lvl = 0;
}

void	main_fractal(t_fractol *f)
{
	if (f->fractol == 'm')
		f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Mandelbrot");
	else
		f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Julia");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
	reset(f);
	/* Normal flow */
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 6, 1L<<6, mouse_move, f);
	mlx_hook(f->win, 17, 0, quit, f);
	mlx_expose_hook(f->win, expose, f);
	mlx_loop(f->mlx);
	/*---End of normal flow*/
	/* Created for performance testing*/
	/*key_hook(65364, f);
	key_hook(65364, f);
	key_hook(65364, f);
	key_hook(65364, f);
	key_hook(65364, f);
	key_hook(65364, f);
	key_hook(113, f);*/
	/* End of performance test */
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	//ft_printf("MINE PRINTF!!\n\n");
	if (argc < 2 || argc > 4)
	{
		//printf("too much or too little args");
		message();
		exit(1);
	}
	/*if (argc == 3)
	{
		double valor;
		valor = ft_atof(argv[2]);
		printf ("\nDouble com valor de: %lf\n\n", valor);
	}*/
	//if (argc == 2 && (argv[1][0] == 'm' || argv[1][0] == 'j'))
	if (argv[1][0] == 'm' || argv[1][0] == 'j')
	{
		f.fractol = argv[1][0];
		if (f.fractol == 'm')
			set_mandelbrot(&f);
		else
		{
			f.cr = ft_atof(argv[2]);
			f.ci = ft_atof(argv[3]);
			set_julia(&f);
			printf("Julia, cr: %lf ci: %lf\n", f.cr, f.ci);
		}
		main_fractal(&f);
	}
	else
		message();
	exit(0);
}

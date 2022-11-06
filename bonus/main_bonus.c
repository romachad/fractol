/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:44:33 by romachad          #+#    #+#             */
/*   Updated: 2022/11/04 00:14:11 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/ft_printf.h"

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
		if (f.fractol == 'j')
		{
			f.cr = ft_atof(argv[2]);
			f.ci = ft_atof(argv[3]);
		}
		f.mlx = mlx_init();
		main_fractal(&f);
	}
	else
		message();
	exit(0);
}

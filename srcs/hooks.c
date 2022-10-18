/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:08:48 by romachad          #+#    #+#             */
/*   Updated: 2022/10/18 00:33:33 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/buttons.h"

#include <stdio.h>
int	key_hook(int keycode, t_fractol *f)
{
	//double tmp;
	printf("Key pressed: %i\n", keycode);
	if (keycode == LEFT)
	{
		f->tmp = f->min_r;
		f->min_r -= (f->max_r - f->min_r) * 0.05;
		f->max_r -= (f->max_r - f->tmp) * 0.05;
		/*f->min_r -= 0.2;
		f->max_r -= 0.2;*/
//		mlx_destroy_image(f->mlx, f->img);
//		f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
		f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
		draw_fractal(f);
		//draw_change(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	}
	else if (keycode == RIGHT)
	{
		f->tmp = f->min_r;
		f->min_r += (f->max_r - f->min_r) * 0.05;
		f->max_r += (f->max_r - f->tmp) * 0.05;
		/*f->min_r += 0.2;
		f->max_r += 0.2;*/
		//mlx_destroy_image(f->mlx, f->img);
		//f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
		//mlx_destroy_image(f->mlx, f->img);
		/*int x;
		x = 0.2 / ((f->max_r - f->min_r) / WIDTH);*/
	//	f->start_X = (0.2 / ((f->max_r - f->min_r) / WIDTH));
	//	f->start_X = WIDTH - f->start_X - 1;
		f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
		draw_fractal(f);
		//draw_change(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	}
	else if (keycode == UP)
	{
		f->tmp = f->min_i;
		f->min_i -= (f->max_i - f->min_i) * 0.05;
		f->max_i -= (f->max_i - f->tmp) * 0.05;
		f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
		draw_fractal(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	}
	else if (keycode == DOWN)
	{
		f->tmp = f->min_i;
		f->min_i += (f->max_i - f->min_i) * 0.05;
		f->max_i += (f->max_i - f->tmp) * 0.05;
		f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
		draw_fractal(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	}
	else if (keycode == PLUS_KEY)
	{
		f->tmp = f->min_r;
		f->min_r = f->max_r + INC_Z * (f->min_r - f->max_r);
		f->max_r = f->max_r + ((f->tmp - f->max_r) - INC_Z * (f->tmp -f->max_r)) / 2;
		f->tmp = f->min_i;
		f->min_i = f->max_i + INC_Z * (f->min_i - f->max_i);
		f->max_i = f->max_i + ((f->tmp - f->max_i) - INC_Z * (f->tmp -f->max_i)) / 2;
		f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
		draw_fractal(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	}
	else if (keycode == MINUS_KEY)
	{
		f->tmp = f->min_r;
		f->min_r = f->max_r + DEC_Z * (f->min_r - f->max_r);
		f->max_r = f->max_r + ((f->tmp - f->max_r) - DEC_Z * (f->tmp -f->max_r)) / 2;
		f->tmp = f->min_i;
		f->min_i = f->max_i + DEC_Z * (f->min_i - f->max_i);
		f->max_i = f->max_i + ((f->tmp - f->max_i) - DEC_Z * (f->tmp -f->max_i)) / 2;
		f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
		draw_fractal(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	}
	else if (keycode == ESC || keycode == Q)
		quit(f);
	else if (keycode == R)
	{
		f->min_r = -2;
		f->max_r = 1;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
		draw_fractal(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		printf("min_r: %f\nmax_r: %f\nmin_i: %f\nmax_i: %f\n",f->min_r, f->max_r, f->min_i, f->max_i);
	}
	return (0);
}

int	mouse_hook(int mousecode)
{
	printf("Mouse pressed: %i\n", mousecode);
	return (0);
}

int	mouse_move(int x, int y)
{
	printf("Mouse coord: X=%i\tY=%i\n",x, y);
	return (0);
}


		/*Teoretical code to calculate ONLY the new area **DOES NOT WORK**
		f->min_r += 0.75;
		f->max_r += 0.75;
		mlx_put_image_to_window(f->mlx, f->win, f->img, -250, 0);
		f->start_X = 750;
		f->img2 = mlx_new_image(f->mlx, 250, HEIGHT);
		f->addr2 = mlx_get_data_addr(f->img2, &f->bits_per_pixel, &f->line_length, &f->endian);
		draw_change(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img2, 750, 0);*/
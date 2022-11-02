/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:08:48 by romachad          #+#    #+#             */
/*   Updated: 2022/11/02 03:22:24 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/buttons.h"

#include <stdio.h>
//int	mouse_hook(int mousecode, t_fractol f);
int	key_hook(int keycode, t_fractol *f)
{
	printf("Key pressed: %i\n", keycode);
	if (keycode == LEFT)
		left(f);
	if (keycode == RIGHT)
		right(f);
	if (keycode == UP)
		up(f);
	if (keycode == DOWN)
		down(f);
	if (keycode == PLUS_KEY)
		increase_zoom(f);
	if (keycode == MINUS_KEY)
		decrease_zoom(f);
	if (keycode == ESC || keycode == Q)
		quit(f);
	if (keycode == R)
		reset(f);
	printf("addr: %p\n", &f);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	printf("Mouse pressed: %i ; x=%i y=%i\n", mousecode,x,y);
	if (mousecode == SCROLL_FW)
	{
		//printf("\naddr: %p\n", &f);
		//key_hook(PLUS_KEY, f);
		/*f->min_r = -2;
		f->max_r = 1;
		f->min_i = -1.5;
		f->max_i = 1.5;*/
		increase_zoom(f);
	}
	if (mousecode == SCROLL_BW)
		decrease_zoom(f);
	return (0);
}

int	mouse_move(int x, int y)
{
	printf("Mouse coord: X=%i\tY=%i\n",x, y);
	return (0);
}

int	expose(t_fractol *f)
{
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
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

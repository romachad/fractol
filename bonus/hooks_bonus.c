/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:08:48 by romachad          #+#    #+#             */
/*   Updated: 2022/11/06 06:03:12 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/buttons.h"
#include "../headers/ft_printf.h"

int	key_hook(int keycode, t_fractol *f)
{
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
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	if (x < 0 || x > WIDTH)
		return (0);
	if (y < 0 || y > HEIGHT)
		return (0);
	if (mousecode == SCROLL_FW)
	{
		f->is_zoom = 1;
		center(x, y, f);
		increase_zoom(f);
	}
	if (mousecode == SCROLL_BW)
	{
		f->is_zoom = 1;
		center(x, y, f);
		decrease_zoom(f);
	}
	if (mousecode == R_CLICK)
		center(x, y, f);
	return (0);
}

int	expose(t_fractol *f)
{
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

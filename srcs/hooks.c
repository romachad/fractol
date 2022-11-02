/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:08:48 by romachad          #+#    #+#             */
/*   Updated: 2022/11/02 05:34:26 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/buttons.h"
#include "../headers/ft_printf.h"

int	key_hook(int keycode, t_fractol *f)
{
	ft_printf("Key pressed: %i\n", keycode);
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
	ft_printf("Mouse pressed: %i ; x=%i y=%i\n", mousecode, x, y);
	if (mousecode == SCROLL_FW)
		increase_zoom(f);
	if (mousecode == SCROLL_BW)
		decrease_zoom(f);
	return (0);
}

int	mouse_move(int x, int y)
{
	ft_printf("Mouse coord: X=%i\tY=%i\n", x, y);
	return (0);
}

int	expose(t_fractol *f)
{
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

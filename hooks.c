/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:08:48 by romachad          #+#    #+#             */
/*   Updated: 2022/10/13 01:42:19 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "buttons.h"

#include <stdio.h>
int	key_hook(int keycode, t_fractol *f)
{
	//double tmp;
	printf("Key pressed: %i\n", keycode);
	if (keycode == LEFT)
	{
		//tmp = f->min_r;
		/*f->min_r -= (f->max_r - f->min_r) * 0.2;
		f->max_r -= (f->max_r - tmp) * 0.2;*/
		f->min_r -= 0.2;
		f->max_r -= 0.2;
		/*int x;
		x = 0.2 / ((f->max_r - f->min_r)/WIDTH);
		printf("x eh: %i\n",x);*/
		//printf("Df max r e minr: %f", (f->max_r - f->min_r));
		draw_fractal(f);
		//draw_change(f, 0, 0);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	else if (keycode == SPACE)
	{
		f->min_r -= 0.5;
		f->max_r -= 0.5;
		draw_fractal(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
	else if (keycode == RIGHT)
	{
		/*tmp = f->min_r;
		f->min_r += (f->max_r - f->min_r) * 0.2;
		f->max_r += (f->max_r - tmp) * 0.2;*/
		f->min_r += 0.2;
		f->max_r += 0.2;
		/*int x;
		x = 0.2 / ((f->max_r - f->min_r) / WIDTH);*/
		draw_fractal(f);
		//draw_change(f, 0, 0);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
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

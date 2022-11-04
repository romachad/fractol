/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:15:48 by romachad          #+#    #+#             */
/*   Updated: 2022/11/04 00:16:48 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/ft_printf.h"

void	increase_zoom(t_fractol *f)
{
	f->tmp = f->min_r;
	f->min_r = f->max_r + INC_Z * (f->min_r - f->max_r);
	f->max_r = f->max_r + ((f->tmp - f->max_r) - INC_Z * (f->tmp - f->max_r));
	f->tmp = f->min_i;
	f->min_i = f->max_i + INC_Z * (f->min_i - f->max_i);
	f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	f->is_zoom = 0;
	f->z_lvl++;
	ft_printf("Zoom level: %d\n", f->z_lvl);
	draw_fractal(f);
}

void	decrease_zoom(t_fractol *f)
{
	f->tmp = f->min_r;
	f->min_r = f->max_r + DEC_Z * (f->min_r - f->max_r);
	f->max_r = f->max_r + ((f->tmp - f->max_r) - DEC_Z * (f->tmp - f->max_r));
	f->tmp = f->min_i;
	f->min_i = f->max_i + DEC_Z * (f->min_i - f->max_i);
	f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	f->is_zoom = 0;
	f->z_lvl--;
	ft_printf("Zoom level: %d\n", f->z_lvl);
	draw_fractal(f);
}

void	reset(t_fractol *f)
{
	f->is_zoom = 0;
	f->z_lvl = 0;
	if (f->fractol == 'm')
	{
		f->min_r = -2;
		f->max_r = 1;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	}
	else if (f->fractol == 'j')
	{
		f->min_r = -1.5;
		f->max_r = 1.5;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	}
	else
	{
		f->min_r = -3;
		f->max_r = 3;
		f->min_i = -3;
		f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	}
	draw_fractal(f);
}

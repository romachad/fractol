/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:10:32 by romachad          #+#    #+#             */
/*   Updated: 2022/11/05 18:10:36 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	first_color(t_fractol *f)
{
	int	color;

	color = f->n * 0x1000;
	color = 0x00A0FF - color;
	return (color);
}

int	second_color(t_fractol *f)
{
	int	color;

	color = ((f->n - 1) % 10) * 0x1000;
	color = 0xFFFF00 - color;
	return (color);
}

int	third_color(t_fractol *f)
{
	int	color;

	color = ((f->n - 1) % 10) * 0x0A0000;
	color = 0xCC0000 - color;
	return (color);
}

int	fourth_color(t_fractol *f)
{
	int	color;

	color = ((f->n - 1) % 10) * 0x0B0B00;
	color = 0x66FFFF - color;
	return (color);
}

int	fifth_color(t_fractol *f)
{
	int	color;

	color = ((f->n - 1) % 10) * 0x040400;
	color = 0x3399FF - color;
	return (color);
}

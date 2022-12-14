/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:15:28 by romachad          #+#    #+#             */
/*   Updated: 2022/11/05 21:28:10 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	center(int x, int y, t_fractol *f)
{
	double	dist_r;
	double	dist_i;

	dist_r = (((double)x * (f->max_r - f->min_r)) / WIDTH);
	dist_i = (((double)y * (f->max_i - f->min_i)) / HEIGHT);
	dist_r = dist_r - ((f->max_r - f->min_r) / 2);
	f->min_r += dist_r;
	f->max_r += dist_r;
	dist_i = dist_i - ((f->max_i - f->min_i) / 2);
	f->min_i += dist_i;
	f->max_i += dist_i;
	if (!f->is_zoom)
		draw_fractal(f);
}

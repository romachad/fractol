/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:10:41 by romachad          #+#    #+#             */
/*   Updated: 2022/11/05 18:10:45 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	sixth_color(t_fractol *f)
{
	int	color;

	color = ((f->n - 1) % 10) * 0x050005;
	color = 0xD700D7 - color;
	return (color);
}

int	seventh_color(t_fractol *f)
{
	int	color;

	color = ((f->n - 1) % 10) * 0x100011;
	color = 0x990099 - color;
	return (color);
}

int	eighth_color(t_fractol *f)
{
	int	color;

	color = ((f->n - 1) % 10) * 0x050000;
	color = 0x990099 - color;
	return (color);
}

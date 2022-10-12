/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:08:48 by romachad          #+#    #+#             */
/*   Updated: 2022/10/13 00:16:02 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>
int	key_hook(int keycode, t_fractol *f)
{
	printf("Key pressed: %i\n", keycode);
	return (0);
}

int	mouse_hook(int mousecode, t_fractol *f)
{
	printf("Mouse pressed: %i\n", mousecode);
	return (0);
}

int	mouse_move(int x, int y, t_fractol *f)
{
	printf("Mouse coord: X=%i\tY=%i\n",x, y);
	return (0);
}

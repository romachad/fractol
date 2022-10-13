/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:04:31 by romachad          #+#    #+#             */
/*   Updated: 2022/10/13 02:10:17 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# define MAX_ITER 80
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	X;
	int	Y;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}	t_fractol;

void	mandelbrot(t_fractol *f, double cr, double ci);
void	mandelbrot2(t_fractol *f, double cr, double ci);
//void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	my_mlx_pixel_put(t_fractol *data, int color);
int	key_hook(int keycode, t_fractol *f);
int	mouse_hook(int mousecode);
int	mouse_move(int x, int y);
void	draw_fractal(t_fractol *f);
void	draw_change(t_fractol *f, int x, int y);

#endif

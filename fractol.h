/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:04:31 by romachad          #+#    #+#             */
/*   Updated: 2022/10/13 23:21:58 by coret            ###   ########.fr       */
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
	//void	*img2;
	char	*addr;
	//char	*addr2;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	X;
	int	Y;
	int	start_X; //possible to be removed
	int	start_Y; // possible to be removed
	int	max_WIDTH; //possible to be removed
	int	draw_width;
	int	draw_height;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	tmp;
}	t_fractol;

void	mandelbrot(t_fractol *f, double cr, double ci);
void	mandelbrot2(t_fractol *f, double cr, double ci);
//void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	my_mlx_pixel_put(t_fractol *data, int color);
void	my_mlx_pixel_put2(t_fractol *data, int color);
int	key_hook(int keycode, t_fractol *f);
int	mouse_hook(int mousecode);
int	mouse_move(int x, int y);
void	draw_fractal(t_fractol *f);
void	draw_change(t_fractol *f);
int	render_next_frame(t_fractol *f);

#endif

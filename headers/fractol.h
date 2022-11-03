/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:04:31 by romachad          #+#    #+#             */
/*   Updated: 2022/11/03 20:10:08 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# define MAX_ITER 80
# define WIDTH 800
# define HEIGHT 800
# define INC_Z 0.75
# define DEC_Z 1.50
# define NEWTON_R1 1
# define NEWTON_R2 0.5
# define NEWTON_R3 0.866025403784438

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	tmp;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	char	fractol;
	int		n;
}	t_fractol;

void	fractal(t_fractol *f);
void	newton(t_fractol *f);
void	root_distance(t_fractol *f);
void	my_mlx_pixel_put(t_fractol *data, int color);
void	my_mlx_pixel_put_newton(t_fractol *data, int color);
int		key_hook(int keycode, t_fractol *f);
int		mouse_hook(int mousecode, int x, int y, t_fractol *f);
int		mouse_move(int x, int y);
void	draw_fractal(t_fractol *f);
int		render_next_frame(t_fractol *f);
int		quit(t_fractol *f);
void	left(t_fractol *f);
void	right(t_fractol *f);
void	up(t_fractol *f);
void	down(t_fractol *f);
void	increase_zoom(t_fractol *f);
void	decrease_zoom(t_fractol *f);
void	reset(t_fractol *f);
double	ft_atof(const char *str);
int		expose(t_fractol *f);
void	message(void);

#endif

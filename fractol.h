/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:04:31 by romachad          #+#    #+#             */
/*   Updated: 2022/10/09 19:22:35 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# define MAX_ITER 80
# define WIDTH 900
# define HEIGHT 900

/*typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}	t_fractol;
*/
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}	t_fractol;

void	mandelbrot(t_fractol *f, int x, int y, double cr, double ci);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);

#endif

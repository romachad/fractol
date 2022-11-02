/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:20:41 by romachad          #+#    #+#             */
/*   Updated: 2022/11/02 05:02:48 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/ft_printf.h"

int	quit(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
	return (0);
}

void	message(void)
{
	ft_printf("Invalid option(s)! Please use the arguments as shown below:\n\
		1- m for Mandelbrot or j for Julia\n\
		2- A value for the Real number (e.g.: -0.54) --Valid only for Julia Fractol\n\
		3- A value for the Imaginary number (e.g.: 0.54) --Valid");
	ft_printf(" only for Julia Fractol\n");
	ft_printf("WARNING: Using set julia without providing arguments ");
	ft_printf("2 and 3 they will be assumed as zero.\n");
	ft_printf("\nBelow are some examples for the Julia set:\n");
	ft_printf("./fractol j 0 0.8\n./fractol j 0.355534 -0.337292\n");
	ft_printf("./fractol j 0.3125 0.566176471\n");
}

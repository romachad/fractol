
#include "../headers/fractol.h"

void	left(t_fractol *f)
{
	f->tmp = f->min_r;
	f->min_r -= (f->max_r - f->min_r) * 0.05;
	f->max_r -= (f->max_r - f->tmp) * 0.05;
	draw_fractal(f);
}

void	right(t_fractol *f)
{
	f->tmp = f->min_r;
	f->min_r += (f->max_r - f->min_r) * 0.05;
	f->max_r += (f->max_r - f->tmp) * 0.05;
	draw_fractal(f);
}

void	up(t_fractol *f)
{
	f->tmp = f->min_i;
	f->min_i -= (f->max_i - f->min_i) * 0.05;
	f->max_i -= (f->max_i - f->tmp) * 0.05;
	draw_fractal(f);
}

void	down(t_fractol *f)
{
	f->tmp = f->min_i;
	f->min_i += (f->max_i - f->min_i) * 0.05;
	f->max_i += (f->max_i - f->tmp) * 0.05;
	draw_fractal(f);
}


#include "../headers/fractol.h"
#include <stdio.h> //REMOVER!!!
void	increase_zoom(t_fractol *f)
{
	f->tmp = f->min_r;
	f->min_r = f->max_r + INC_Z * (f->min_r - f->max_r);
	f->max_r = f->max_r + ((f->tmp - f->max_r) - INC_Z * (f->tmp -f->max_r));
	f->tmp = f->min_i;
	f->min_i = f->max_i + INC_Z * (f->min_i - f->max_i);
	f->max_i = f->max_i + ((f->tmp - f->max_i) - INC_Z * (f->tmp -f->max_i));
	draw_fractal(f);
}

void	decrease_zoom(t_fractol *f)
{
	f->tmp = f->min_r;
	f->min_r = f->max_r + DEC_Z * (f->min_r - f->max_r);
	f->max_r = f->max_r + ((f->tmp - f->max_r) - DEC_Z * (f->tmp -f->max_r));
	f->tmp = f->min_i;
	f->min_i = f->max_i + DEC_Z * (f->min_i - f->max_i);
	f->max_i = f->max_i + ((f->tmp - f->max_i) - DEC_Z * (f->tmp -f->max_i));
	draw_fractal(f);
}

void	reset(t_fractol *f)
{
	if (f->fractol == 'm')
	{
		f->min_r = -2;
		f->max_r = 1;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
	}
	else
	{
		f->min_r = -1.5;
		f->max_r = 1.5;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * (HEIGHT / WIDTH);
		f->cr = -0.54;
		f->ci = 0.54;
	}
	draw_fractal(f);
}

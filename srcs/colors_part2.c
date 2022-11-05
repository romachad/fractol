
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

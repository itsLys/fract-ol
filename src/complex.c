#include "fractol.h"
#include <stdio.h>
//     re, im
// MIN[-2, -2]
// MAX[2, 2]
t_complex map_pixel(t_point p, t_data *data)
{
	t_complex	c;

	c.re = ((data->range[0].re + (p.x * ((data->range[1].re - data->range[0].re) / WIN_WIDTH)))
		* data->scale) + (data->shift.re);
	c.im = ((data->range[0].im + (p.y * ((data->range[1].im - data->range[0].im) / WIN_HEIGHT)))
		* data->scale) + (data->shift.im);
	return ((t_complex) c);
}

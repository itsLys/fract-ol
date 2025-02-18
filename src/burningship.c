#include "fractol.h"

inline static t_complex map_pixel(t_point p, t_data *data)
{
	t_complex	c;

	c.re = ((data->range[0].re + (p.x * ((data->range[1].re - data->range[0].re) / WIN_WIDTH)))
		* data->scale) + (data->shift.re);
	c.im = ((data->range[0].im + (p.y * ((data->range[1].im - data->range[0].im) / WIN_HEIGHT)))
		* data->scale) + (data->shift.im);
	return ((t_complex) c);
}

inline static int	check_point(t_complex c, t_data *data)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z.im = 0.0;
	z.re = 0.0;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4.0 && i < data->iter)
	{
		tmp.re = z.re * z.re - z.im * z.im  + c.re;
		tmp.im = fabs(z.re) * fabs(z.im) * 2 + c.im;
		z = tmp;
		i++;
	}
	return (i);
}

void	render_burningship(t_data *data)
{
	t_point		p;
	t_complex	c;
	int			iter;
	double		index;

	data->range[0] = (t_complex) {-2.0, -2};
	data->range[1] = (t_complex) {2, 2};
	p.y = 0;
	while (p.y < WIN_WIDTH)
	{
		p.x = 0;
		while (p.x < WIN_HEIGHT)
		{
			c = map_pixel(p, data);
			iter = check_point(c, data);
			index = ((double) iter / data->iter) * (TABLE_SIZE - 1);
			if (iter == data->iter)
				img_put_pixel(data, p.x, p.y, 0x0);
			else
				img_put_pixel(data, p.x, p.y, data->color_table[(int)index]);
			p.x++;
		}
		p.y++;
	}
}

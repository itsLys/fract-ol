/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:19:02 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 11:19:51 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline static t_complex	map_pixel(t_point p, t_data *data)
{
	t_complex	c;

	c.re = ((data->range[0].re + (p.x
					* ((data->range[1].re - data->range[0].re) / WIN_WIDTH)))
			* data->scale) + (data->shift.re);
	c.im = ((data->range[0].im + (p.y
					* ((data->range[1].im - data->range[0].im) / WIN_HEIGHT)))
			* data->scale) + (data->shift.im);
	return ((t_complex) c);
}

int	handle_motion(int x, int y, t_data *data)
{
	data->mouse_pos = map_pixel((t_point){x, y}, data);
	if (data->toggle_mouse_param)
		data->julia_params = data->mouse_pos;
	return (0);
}

int	handle_keypress(int code, t_data *data)
{
	if (code == XK_Right || code == XK_Left || code == XK_Up
		|| code == XK_Down)
		handle_move(code, data);
	else if (code == XK_minus || code == XK_equal)
		handle_zoom(code, data);
	else if (code == XK_space)
		reset_defaults(data);
	else if (code == XK_c)
		change_color(data);
	else if (code == XK_j || code == XK_m || code == XK_n
		|| code == XK_e || code == XK_b)
		change_fractal(code, data);
	else if (code == XK_Escape)
		exit_program(data);
	else if (code == XK_s)
		toggle_mouse_param(data);
	else if (code == XK_r || code == XK_t)
		handle_color_shift(code, data);
	return (0);
}

int	handle_button(int code, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (code == 4 || code == 5)
		handle_zoom(code, data);
	return (0);
}

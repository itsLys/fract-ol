/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:49:24 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 10:49:30 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_defaults(t_data *data)
{
	data->shift.re = 0;
	data->shift.im = 0;
	data->scale = 1;
	data->iter = BASE_ITER;
	data->julia_params = data->default_julia_params;
}

void	change_fractal(int code, t_data *data)
{
	if (code == XK_m)
		data->fractal = 'm';
	else if (code == XK_j)
		data->fractal = 'j';
	else if (code == XK_n)
		data->fractal = 'n';
	else if (code == XK_e)
		data->fractal = 'e';
	else if (code == XK_b)
		data->fractal = 'b';
}

void	toggle_mouse_param(t_data *data)
{
	if (data->toggle_mouse_param)
		data->toggle_mouse_param = 0;
	else
		data->toggle_mouse_param = 1;
}

void	handle_color_shift(int code, t_data *data)
{
	if (code == XK_r)
	{
		if (data->color_shift == 20)
			data->color_shift = 0;
		else
			data->color_shift++;
	}
	else if (code == XK_t)
	{
		if (data->color_shift == 0)
			data->color_shift = 20;
		else
			data->color_shift--;
	}
	free(data->color_table);
	data->color_table = init_colors(data->color, data);
}

void	change_color(t_data *data)
{
	if (data->color == 3)
		data->color = 0;
	else
		data->color += 1;
	free(data->color_table);
	data->color_table = init_colors(data->color, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:15:04 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 11:15:14 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_move(int code, t_data *data)
{
	if (code == XK_Left)
		data->shift.re -= SHIFT_STEP * data->scale;
	else if (code == XK_Right)
		data->shift.re += SHIFT_STEP * data->scale;
	else if (code == XK_Up)
		data->shift.im -= SHIFT_STEP * data->scale;
	else if (code == XK_Down)
		data->shift.im += SHIFT_STEP * data->scale;
}

static int	calculate_iterations(double scale)
{
	double	iter;

	iter = BASE_ITER + log2(1 / scale) * ITER_STEP;
	if (iter < MIN_ITER)
		return (MIN_ITER);
	else if (iter > MAX_ITER)
		return (MAX_ITER);
	else
		return ((int)iter);
}

void	handle_zoom(int code, t_data *data)
{
	if (code == XK_equal || code == 4)
	{
		data->shift.re = data->shift.re
			* SCALE_STEP + data->mouse_pos.re * (1 - SCALE_STEP);
		data->shift.im = data->shift.im
			* SCALE_STEP + data->mouse_pos.im * (1 - SCALE_STEP);
		data->scale *= SCALE_STEP;
	}
	if (code == XK_minus || code == 5)
	{
		data->shift.re = (data->shift.re - data->mouse_pos.re)
			/ SCALE_STEP + data->mouse_pos.re;
		data->shift.im = (data->shift.im - data->mouse_pos.im)
			/ SCALE_STEP + data->mouse_pos.im;
		data->scale /= SCALE_STEP;
	}
	data->iter = calculate_iterations(data->scale);
}

#include "fractol.h"

void handle_move(int code, t_data *data)
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

int calculate_iterations(double scale)
{
	double iter;

	iter = BASE_ITER + log2(1 / scale) * ITER_STEP;
	if (iter < MIN_ITER)
		return MIN_ITER;
	else if (iter > MAX_ITER)
		return MAX_ITER;
	else
		return (int) iter;
}

void handle_zoom(int code, t_data *data)
{
	if (code == XK_equal || code == 4)
		data->scale *= SCALE_STEP;
	if (code == XK_minus || code == 5)
		data->scale /= SCALE_STEP;
	data->iter = calculate_iterations(data->scale);
	data->shift.re = data->shift.re * SCALE_STEP + data->mouse_pos.re * (1 - SCALE_STEP);
	data->shift.im = data->shift.im * SCALE_STEP + data->mouse_pos.im * (1 - SCALE_STEP);
}

void  reset_defaults(t_data *data)
{
	data->shift.re = 0;
	data->shift.im = 0;
	data->scale = 1;
	data->color = 1;
	data->iter = BASE_ITER;
}

void change_color(t_data *data)
{
	if (data->color == 3)
		data->color = 0;
	else
		data->color += 1;
	free(data->color_table);
	data->color_table = init_colors(data->color, data);
}

void change_fractal(int code, t_data *data)
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

void toggle_mouse_param(t_data *data)
{
	if (data->toggle_mouse_param)
		data->toggle_mouse_param = 0;
	else
		data->toggle_mouse_param = 1;
}

void handle_color_shift(int code, t_data *data)
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

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

void handle_zoom_and_iterations(int code, t_data *data)
{
	double iter;
	if (code == XK_equal || code == 4)
		data->scale *= SCALE_STEP;
	if (code == XK_minus || code == 5)
		data->scale /= SCALE_STEP;
	iter = BASE_ITER + log2(1 / data->scale) * ITER_STEP;
	if (iter < MIN_ITER)
		data->iter = MIN_ITER;
	else if (iter > MAX_ITER)
		data->iter = MAX_ITER;
	else
		data->iter =  (int) iter;
	data->shift.re = data->shift.re * SCALE_STEP + data->mouse_pos.re * (1 - SCALE_STEP);
	data->shift.im = data->shift.im * SCALE_STEP + data->mouse_pos.im * (1 - SCALE_STEP);
}

#include "fractol.h"

int handle_motion(int x, int y, t_data *data)
{
	data->mouse_pos = map_pixel((t_point) {x, y}, data);
	if (data->toggle_mouse_param)
		data->julia_params = data->mouse_pos;
	return 0;
}

int handle_keypress(int code, t_data *data)
{
	if (code == XK_Right || code == XK_Left || code == XK_Up
		|| code == XK_Down)
		handle_move(code, data);
	else if (code == XK_minus || code == XK_equal)
		handle_zoom_and_iterations(code, data);
	else if (code == XK_space)
		reset_defaults(data);
	else if (code == XK_c)
		change_color(data);
	else if (code == XK_j || code == XK_m || code == XK_n || code == XK_e || code == XK_b)
		change_fractal(code, data);
	else if (code == XK_Escape)
		exit_program(data);
	else if (code == XK_s)
		toggle_mouse_param(data);
	else if (code == XK_r || code == XK_t)
		handle_color_shift(code, data);
	return (0);
}

int handle_button(int code, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (code == 4 || code == 5)
		handle_zoom_and_iterations(code, data);
	return 0;
}


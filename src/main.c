/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:55:40 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/17 22:50:15 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include <stdlib.h>

int exit_program(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->color_table)
		free(data->color_table);
	free(data->mlx);
	free(data);
	exit (FAILIURE);
}

static void init_members(t_data *data)
{
	data->shift.im = 0;
	data->shift.re = 0;
	data->scale = 1;
	data->iter = BASE_ITER;
	data->color = GRAYSCALE;
	data->color_table = init_colors(data->color, data);
	data->default_julia_params = (t_complex) {-0.5, 0.5};
	data->julia_params = data->default_julia_params;
	data->toggle_mouse_param = 0;
	data->color_shift = 0;
}

static t_data *init_data(void)
{
	static t_data *data;

	data = ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		exit(1);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(1);
	data->win = mlx_new_window(data->mlx, WIN_HEIGHT, WIN_WIDTH, "fractol");
	if (data->win == NULL)
		exit_program(data);
	data->img.img = mlx_new_image(data->mlx, WIN_HEIGHT, WIN_WIDTH);
	if (data->img.img == NULL)
		exit_program(data);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
									&data->img.line_len, &data->img.endian);
	init_members(data);
	return (data);
}

static void setup_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, &exit_program, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, &handle_motion, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, &handle_button, data);
}

static void render(t_data *data)
{
	mlx_loop_hook(data->mlx, &render_img, data);
	mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	t_data *data;

	data = init_data();
	if (parse_args(ac, av, data) == FAILIURE)
		exit_program(data);
	setup_hooks(data);
	render(data);
	return (0);
}

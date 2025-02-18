/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:56:13 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 10:32:35 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "defs.h"

void	render_mandelbrot(t_data *data);
void	render_julia(t_data *data);
void	render_newton(t_data *data);
void	render_custom(t_data *data);
void	render_burningship(t_data *data);
void	handle_move(int code, t_data *data);
void	handle_zoom(int code, t_data *data);
void	reset_defaults(t_data *data);
void	change_color(t_data *data);
void	change_fractal(int code, t_data *data);
void	toggle_mouse_param(t_data *data);
void	handle_color_shift(int code, t_data *data);
void	img_put_pixel(t_data *data, int x, int y, int color);
int		handle_motion(int x, int y, t_data *data);
int		handle_keypress(int code, t_data *data);
int		handle_button(int code, int x, int y, t_data *data);
int		exit_program(t_data *data);
int		render_img(t_data *data);
int		*init_colors(int flag, t_data *data);
int		parse_args(int ac, char **av, t_data *data);

#endif // !FRACTOL_H

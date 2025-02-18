/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:56:13 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/17 22:56:17 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <X11/keysym.h> // legallity of use?
#include <X11/X.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include "defs.h"


int exit_program(t_data *data);
// //utils
// t_complex map_pixel(t_point p, t_data *data);

// fractals
void render_mandelbrot(t_data *data);
void render_julia(t_data *data);
void render_newton(t_data *data);
void render_custom(t_data *data);
void render_burningship(t_data *data);

// hooks
void handle_move(int code, t_data *data);
int handle_motion(int x, int y, t_data *data);
int handle_keypress(int code, t_data *data);
void handle_zoom_and_iterations(int code, t_data *data);
void reset_defaults(t_data *data); // resets color, zoom, shift, iterations;
void change_color(t_data *data);
void change_fractal(int code, t_data *data);
int handle_button(int code, int x, int y, t_data *data);
void toggle_mouse_param(t_data *data);
void handle_color_shift(int code, t_data *data);


// rendering
void img_put_pixel(t_data *data, int x, int y, int color);
int render_img(t_data *data);
int *init_colors(int flag, t_data *data);

// parser
int parse_args(int ac, char **av, t_data *data);

#endif // !FRACTOL_H

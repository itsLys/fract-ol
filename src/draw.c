/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:18:38 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 11:18:38 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;
	t_img	*img;

	img = &(data->img);
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render_img(t_data *data)
{
	if (data->win == NULL)
		return (1);
	if (data->fractal == 'm')
		render_mandelbrot(data);
	else if (data->fractal == 'j')
		render_julia(data);
	else if (data->fractal == 'e')
		render_custom(data);
	else if (data->fractal == 'b')
		render_burningship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

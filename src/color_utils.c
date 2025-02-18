/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:36:46 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 10:44:05 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "color.h"

int	get_gradient(int s, int e, float t)
{
	t_rgb	rgb;

	t = pow(t, 1.5);
	rgb.r_start = (s >> 16) & 0xFF;
	rgb.r_end = (e >> 16) & 0xFF;
	rgb.g_start = (s >> 8) & 0xFF;
	rgb.g_end = (e >> 8) & 0xFF;
	rgb.b_start = s & 0xFF;
	rgb.b_end = e & 0xFF;
	rgb.r = rgb.r_start + (rgb.r_end - rgb.r_start) * t;
	rgb.g = rgb.g_start + (rgb.g_end - rgb.g_start) * t;
	rgb.b = rgb.b_start + (rgb.b_end - rgb.b_start) * t;
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

void	set_fire(int *palette)
{
	palette[0] = 0x00000000;
	palette[1] = 0x00FF0000;
	palette[2] = 0x00FFFF00;
	palette[3] = 0x00FFFFFF;
	palette[4] = 0x00FFFF00;
	palette[5] = 0x00FF0000;
	palette[6] = 0x00000000;
}

void	set_rainbow(int *palette)
{
	palette[0] = 0x00FF0000;
	palette[1] = 0x00FFFF00;
	palette[2] = 0x0000FF00;
	palette[3] = 0x0000FFFF;
	palette[4] = 0x000000FF;
	palette[5] = 0x00FF00FF;
	palette[6] = 0x00FF0000;
}

void	set_hotncold(int *palette)
{
	palette[0] = 0x00FFFFFF;
	palette[1] = 0x000066FF;
	palette[2] = 0x000000FF;
	palette[3] = 0x00333333;
	palette[4] = 0x00FF0080;
	palette[5] = 0x00FF00CC;
	palette[6] = 0x00FFFFFF;
}

void	set_grayscale(int *palette)
{
	palette[0] = 0x00000000;
	palette[1] = 0x00555555;
	palette[2] = 0x00AAAAAA;
	palette[3] = 0x00FFFFFF;
	palette[4] = 0x00AAAAAA;
	palette[5] = 0x00555555;
	palette[6] = 0x00000000;
}

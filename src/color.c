/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:20:15 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 11:22:03 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "color.h"

static int	get_color(int iter, int set, int *palette)
{
	double	t;
	double	index;

	if (set == FIRE)
		set_fire(palette);
	else if (set == RAINBOW)
		set_rainbow(palette);
	else if (set == GRAYSCALE)
		set_grayscale(palette);
	else if (set == HOTNCOLD)
		set_hotncold(palette);
	t = (double) iter / TABLE_SIZE;
	index = t * (PALETTE_SIZE - 1);
	return (get_gradient(palette[(int) index], palette[(int) index + 1]
			, index - (int) index));
}

int	*init_colors(int set, t_data *data)
{
	int	*palette;
	int	*table;
	int	i;
	int	index;
	int	shift;

	i = 0;
	palette = malloc(PALETTE_SIZE * sizeof(int));
	table = malloc(TABLE_SIZE * sizeof(int));
	if (palette == NULL || table == NULL)
		exit_program(data);
	shift = COLOR_SHIFT_STEP * data->color_shift;
	while (i < TABLE_SIZE)
	{
		if (i + shift >= TABLE_SIZE)
			index = TABLE_SIZE - (i + shift);
		else
			index = i + shift;
		table[i] = get_color(index, set, palette);
		i++;
	}
	free(palette);
	return (table);
}

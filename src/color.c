#include "fractol.h"
#include "color.h"


static int get_color(int iter, int set, t_data *data)
{
	int *palette;
	double t;
	double index;

	palette = malloc(PALETTE_SIZE * sizeof(int));
	if (palette == NULL)
		exit_program(data);
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
	return (get_gradient(palette[(int) index], palette[(int) index + 1], index - (int) index));
}

int *init_colors(int set, t_data *data)
{
	int *table;
	int i;
	int shift;

	i = 0;
	table = malloc(TABLE_SIZE * 4);
	shift = COLOR_SHIFT_STEP * data->color_shift;
	while (i < TABLE_SIZE)
	{
		table[i] = get_color(i + shift, set, data);
		i++;
	}
	return table;
}


#include "fractol.h"
#include <stdio.h>


void parse_fractal(char *arg, t_data *data)
{
	if (!ft_strcmp(arg, "mandelbrot"))
		data->fractal = 'm';
	else if (!ft_strcmp(arg, "julia"))
		data->fractal = 'j';
	else if (!ft_strcmp(arg, "burningship"))
		data->fractal = 'b';
	else if (!ft_strcmp(arg, "extra"))
		data->fractal = 'e';

}

int parse_args(int ac, char **av, t_data *data)
{
	if (ac == 1)
		return (FAILIURE);
	if (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia")
		&& ft_strcmp(av[1], "burningship") && ft_strcmp(av[1], "extra"))
		return (FAILIURE);
	parse_fractal(av[1], data);
	if (data->fractal == 'm' || data->fractal == 'e' || data->fractal == 'b')
	{
		if (ac != 2)
			return  FAILIURE;
	}
	else if (data->fractal == 'j')
	{
		if (ac != 4)
			return FAILIURE;
		else if (ft_strisnum(av[2]) == FAILIURE || ft_strisnum(av[3]) == FAILIURE)
			return FAILIURE;
		else 
		{
			data->julia_params.re = ft_atof(av[2]);
			data->julia_params.im = ft_atof(av[3]);
		}
	}
	return SUCCESS;
}

#include "defs.h"
#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"
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

int parse_julia_params(char *p_re, char *p_im, t_data *data)
{
	double	julia_re;
	double	julia_im;

	julia_re = ft_atof(p_re);
	julia_im = ft_atof(p_im);
	
	if (julia_im > 2.0 || julia_im < -2 || julia_re > 2 || julia_im < 2)
	{
		ft_printf("Wrong julia parameter\n");
		ft_printf("Julia sets must be within -2 + -2i and 2 + 2i\n");
		ft_printf("Famous Julia Sets:\n");
		ft_printf("		-0.744 + 0.148\n");
		ft_printf("		-0.8 + 0.156i\n");
		ft_printf("		0.285 + 0.01i\n");
		ft_printf("		0.285 + 0.01i\n");
		ft_printf("		0.4 + 0.06i\n");
		ft_printf("		1 + 1i\n");
		return FAILIURE;
	}
	else
		data->julia_params = (t_complex) {julia_re, julia_im};
	return SUCCESS;
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
		else if (parse_julia_params(av[2], av[3], data) == FAILIURE)
				return FAILIURE;
	}
	return SUCCESS;
}

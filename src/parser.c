#include "fractol.h"

static void	print_error(void)
{
	ft_printf("Error: Invalid Input\n");
	ft_printf("Usage\n./fractol <fractal_name> [parameters]\n");
	ft_printf("Available fractals:\n");
	ft_printf("\tmandelbrot:\t\t\tNo parameters required\n");
	ft_printf("\tburningship:\t\tNo parameters required\n");
	ft_printf("\textra:\t\t\t\tNo parameters required\n");
	ft_printf("\tjulia <Re> <Im>:\tRequires two floating-point numbers\n");
	ft_printf("Examples:\n");
	ft_printf("\t\t./fractol mandelbrot\n");
	ft_printf("\t\t./fractol burningship\n");
	ft_printf("\t\t./fractol julia -0.8 0.156\n\n");
	ft_printf("Wrong julia parameter.\n");
	ft_printf("Julia sets must be within -2 + -2i and 2 + 2i\n");
	ft_printf("Famous Julia Sets:\n");
	ft_printf("\t-0.744 + 0.148i\n");
	ft_printf("\t-0.8 + 0.156i\n");
	ft_printf("\t0.285 + 0.01i\n");
	ft_printf("\t0.285 + 0.01i\n");
	ft_printf("\t0.4 + 0.06i\n");
	ft_printf("\t1 + 1i\n");
}

static void parse_fractal(char *arg, t_data *data)
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

static int parse_julia_params(char *p_re, char *p_im, t_data *data)
{
	double	julia_re;
	double	julia_im;

	julia_re = ft_atof(p_re);
	julia_im = ft_atof(p_im);
	
	if (julia_im > 2.0 || julia_im < -2.0 || julia_re > 2.0 || julia_im < -2.0)
	{
		print_error();
		return FAILIURE;
	}
	else
	{
		data->default_julia_params = (t_complex) {julia_re, julia_im};
		data->julia_params = data->default_julia_params;
	}

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

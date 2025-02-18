/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:29:46 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 10:30:20 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define SUCCESS 0
# define FAILIURE -1
# define BASE_ITER 100
# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define TABLE_SIZE 65536
# define PALETTE_SIZE 7
# define COLOR_SHIFT_STEP 250
# define SHIFT_STEP 0.1
# define SCALE_STEP 0.9
# define ITER_STEP 50
# define MAX_ITER 1000
# define MIN_ITER 100

typedef enum e_color
{
	FIRE,
	RAINBOW,
	HOTNCOLD,
	GRAYSCALE,
}	t_color;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			iter;
	int			color;
	int			*color_table;
	int			fractal;
	int			toggle_mouse_param;
	int			color_shift;
	double		scale;
	t_complex	shift;
	t_complex	mouse_pos;
	t_complex	default_julia_params;
	t_complex	julia_params;
	t_complex	range[2];
	t_img		img;
}	t_data;

#endif // !DEFS_H

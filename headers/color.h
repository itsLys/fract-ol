/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:32:55 by ihajji            #+#    #+#             */
/*   Updated: 2025/02/18 10:43:46 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	r_start;
	int	g_start;
	int	b_start;
	int	r_end;
	int	g_end;
	int	b_end;
}	t_rgb;

int		get_gradient(int s, int e, float t);
void	set_rainbow(int *palette);
void	set_hotncold(int *palette);
void	set_grayscale(int *palette);
void	set_fire(int *palette);

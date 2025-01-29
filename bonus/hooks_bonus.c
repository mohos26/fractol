/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:13:00 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/29 14:36:04 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	close_program(t_vars *vars)
{
	(void)vars;
	exit(0);
	return (0);
}

int	ft_handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_program(vars);
	return (0);
}

void	ft_aid(t_all *ptr, double zoom)
{
	if (ptr->img->set == mandelbrot)
		mandelbrot(ptr->img, zoom);
	else if (ptr->img->set == julia)
		julia(ptr->img, ptr->img->c, zoom);
	else if (ptr->img->set == tricorn)
		tricorn(ptr->img, zoom);
}

int	ft_mouse_hook(int button, int x, int y, t_all *ptr)
{
	static double	zoom;

	x -= y;
	if (button == 4)
	{
		zoom += 0.1;
		ft_aid(ptr, zoom);
		mlx_put_image_to_window(ptr->vars->mlx, ptr->vars->win,
			ptr->img->img, 0, 0);
	}
	else if (button == 5)
	{
		zoom -= 0.1;
		ft_aid(ptr, zoom);
		mlx_put_image_to_window(ptr->vars->mlx, ptr->vars->win,
			ptr->img->img, 0, 0);
	}
	return (0);
}

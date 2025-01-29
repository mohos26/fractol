/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:00:48 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/29 14:36:14 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_aid(int lst[2], double zoom)
{
	t_complex	z;
	t_complex	c;
	double		aid;
	int			iteration;

	z.real = 0;
	z.img = 0;
	c.real = (lst[0] * 1.0 / WIDTH) * (4 - zoom) - 2;
	c.img = (lst[1] * 1.0 / HEIGHT) * (4 - zoom) - 2;
	iteration = 0;
	while (1)
	{
		aid = z.real * z.real + z.img * z.img;
		if (!(aid <= 4 && iteration++ < MAX_ITER))
			break ;
		z = ft_add(ft_pow2(z), c);
	}
	return (iteration + 1 - log2(log2(sqrt(aid))));
}

void	mandelbrot(t_data *img, double zoom)
{
	int			smooth;
	int			lst[2];

	lst[0] = 0;
	while (lst[0]++ < WIDTH)
	{
		lst[1] = 0;
		while (lst[1]++ < HEIGHT)
		{
			smooth = ft_aid(lst, zoom);
			my_mlx_pixel_put(img, lst[0], lst[1], ft_rgb((smooth * 15)
					% 256, (smooth * 1) % 256, (smooth * 10) % 256));
		}
	}
	img->set = mandelbrot;
}

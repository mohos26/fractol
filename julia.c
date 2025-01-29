/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:45:31 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/28 16:04:31 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_aid(int lst[2], t_complex c, double zoom)
{
	t_complex	z;
	double		aid;
	int			iteration;

	z.real = (lst[0] * 1.0 / WIDTH) * (4 - zoom) - 2;
	z.img = (lst[1] * 1.0 / HEIGHT) * (4 - zoom) - 2;
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

void	julia(t_data *img, t_complex c, double zoom)
{
	int			smooth;
	int			lst[2];

	lst[0] = 0;
	while (lst[0]++ < WIDTH)
	{
		lst[1] = 0;
		while (lst[1]++ < HEIGHT)
		{
			smooth = ft_aid(lst, c, zoom);
			my_mlx_pixel_put(img, lst[0], lst[1], ft_rgb((smooth * 10) % 256,
					(smooth * 5) % 256, (smooth * 15) % 256));
		}
	}
	img->set = julia;
	img->c = c;
}

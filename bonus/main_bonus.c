/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:06 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/29 15:11:25 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_exit(char *s)
{
	ft_print(s);
	exit(0);
}

static void	ft_check_input(int ac, char **av)
{
	double	lst[2];

	if (ac > 2 && ft_strncmp(av[1], "julia", 6))
		ft_exit("Number of args !!!\n");
	if (!(ac == 2 || ac == 4) || !(!ft_strncmp(av[1], "mandelbrot", 11)
			|| !ft_strncmp(av[1], "julia", 6)
			|| !ft_strncmp(av[1], "tricorn", 5)))
		ft_exit("Write [mandelbrot - julia - tricorn]\n");
	if (ac == 4)
	{
		if (!(ft_isnumber(av[2], 0) && ft_isnumber(av[3], 0)))
			ft_exit("The Two ars should be numbers.\n");
		lst[0] = ft_isnumber(av[2], 1);
		lst[1] = ft_isnumber(av[3], 1);
		if (!(lst[0] >= -2 && lst[0] <= 2) || !(lst[1] >= -2 && lst[1] <= 2))
			ft_exit("The numbers shold -2 <= number <= 2\n");
	}
}

static void	ft_mlx_init(t_all *aid, t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fractals");
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
			img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	aid->img = img;
	aid->vars = vars;
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_all	aid;

	ft_check_input(ac, av);
	ft_mlx_init(&aid, &vars, &img);
	mlx_key_hook(vars.win, ft_handle_keypress, &vars);
	mlx_hook(vars.win, 17, 0, close_program, NULL);
	mlx_mouse_hook(vars.win, ft_mouse_hook, &aid);
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		mandelbrot(&img, 0);
	else if (!ft_strncmp(av[1], "julia", 6))
	{
		if (ac == 4)
			julia(&img, (t_complex){ft_isnumber(av[2], 1),
				ft_isnumber(av[3], 1)}, 0);
		else
			julia(&img, (t_complex){-1, 0}, 0);
	}
	else if (!ft_strncmp(av[1], "tricorn", 6))
		tricorn(&img, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	exit(0);
}

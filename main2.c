#include <libc.h>
#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1, ft_close, &vars);
	mlx_loop(vars.mlx);
}

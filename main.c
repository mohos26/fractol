#include <libc.h>
#include <mlx.h>
#include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int	ft_rgb(int red, int green, int blue)
{
	return (red * 65536 + green * 256 + blue);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_square(void *mlx_win, t_data *img, int x, int y, int line_length, int color)
{
	int	i;

	i = 1;
	while (i < line_length)
		mlx_pixel_put(&img, mlx_win, x + i++, y, color);
	x += line_length;
	i = 1;
	while (i < line_length)
		mlx_pixel_put(&img, mlx_win, x, y + i++, color);
	y += line_length;
	i = 1;
	while (i < line_length)
		mlx_pixel_put(&img, mlx_win, x - i++, y, color);
	x -= line_length;
	i = 1;
	while (i < line_length)
		mlx_pixel_put(&img, mlx_win, x, y - i++, color);
}

void	ft_draw_specific(void *mlx_win, t_data *img, int x, int y, int line_length, int color)
{
	int	i;

	i = 1;
	while (i <= line_length)
	{
		mlx_pixel_put(&img, mlx_win, x + i, y + i, color);
		i++;
	}
	x += line_length;
	y += line_length;
	i = 1;
	while (i <= line_length)
	{
		mlx_pixel_put(&img, mlx_win, x - i, y + i, color);
		i++;
	}
	x -= line_length;
	y += line_length;
	i = 1;
	while (i <= line_length)
	{
		mlx_pixel_put(&img, mlx_win, x - i, y - i, color);
		i++;
	}
	x -= line_length;
	y -= line_length;
	i = 1;
	while (i <= line_length)
	{
		mlx_pixel_put(&img, mlx_win, x + i, y - i, color);
		i++;
	}
}

void	ft_draw_triangle(void *mlx_win, t_data *img, int x, int y, int line_length, int color)
{
	int i;

	i = 0;
	while (++i < line_length)
		mlx_pixel_put(&img, mlx_win, x + i, y - i, color);
	x += line_length;
	y -= line_length;
	i = 0;
	while (++i < line_length)
		mlx_pixel_put(&img, mlx_win, x + i, y + i, color);
	x += line_length;
	y += line_length;
	i = 1;
	while (i <= line_length * 2)
		mlx_pixel_put(&img, mlx_win, x - i++, y, color);
}

int main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World !!!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	ft_draw_square(mlx_win, &img, 100, 400, 250, ft_rgb(255, 255, 255));
	ft_draw_square(mlx_win, &img, 700, 500, 250, ft_rgb(255, 0, 0));
	ft_draw_square(mlx_win, &img, 578, 50, 50, ft_rgb(255, 0, 255));
	ft_draw_square(mlx_win, &img, 890, 200, 38, ft_rgb(143, 201, 255));

	ft_draw_specific(mlx_win, &img, 303, 608, 161, ft_rgb(165, 32, 25));
	ft_draw_specific(mlx_win, &img, 603, 858, 100, ft_rgb(215, 45, 109));
	ft_draw_specific(mlx_win, &img, 867, 550, 254, ft_rgb(194, 176, 120));
	ft_draw_specific(mlx_win, &img, 800, 470, 121, ft_rgb(234, 137, 154));

	ft_draw_triangle(mlx_win, &img, 1250, 198, 13, ft_rgb(244, 169, 0));
	ft_draw_triangle(mlx_win, &img, 358, 140, 135, ft_rgb(175, 43, 30));
	ft_draw_triangle(mlx_win, &img, 1242, 465, 56, ft_rgb(228, 160, 16));
	ft_draw_triangle(mlx_win, &img, 493, 769, 85, ft_rgb(109, 101, 82));

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	puts("True");
}

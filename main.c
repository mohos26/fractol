#include <libc.h>
#include <mlx.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int	ft_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
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

void	ft_draw_square2(void *mlx_win, t_data *img, int x, int y, int line_length, int color)
{
	int	i;

	i = 1;
	while (i < line_length)
		my_mlx_pixel_put(img, x + i++, y, color);
	x += line_length;
	i = 1;
	while (i < line_length)
		my_mlx_pixel_put(img, x, y + i++, color);
	y += line_length;
	i = 1;
	while (i < line_length)
		my_mlx_pixel_put(img, x - i++, y, color);
	x -= line_length;
	i = 1;
	while (i < line_length)
		my_mlx_pixel_put(img, x, y - i++, color);
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

int ft_add_shade(double distance, int color)
{
	return ((int)(255 * distance) << 24 | color);
}

void	draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x1 - x0 > 0) - (x1 - x0 < 0);
	int sy = (y1 - y0 > 0) - (y1 - y0 < 0);

	int err = dx - dy;

	while (1) {
		mlx_pixel_put(mlx, win, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y0 += sy;
		}
	}
}

void draw_hexagon(void *mlx, void *mlx_win, int x_center, int y_center, int radius, int color)
{
	int x[1000], y[1000];

	// Calculate the vertices
	for (int i = 0; i < 1000; i++) {
		x[i] = x_center + radius * cos(2 * PI * i / 1000);
		y[i] = y_center + radius * sin(2 * PI * i / 1000);
	}

	// Draw the edges
	for (int i = 0; i < 1000; i++) {
		draw_line(mlx, mlx_win, x[i], y[i], x[(i + 1) % 1000], y[(i + 1) % 1000], color);
	}
}

void cleanup_and_exit(void *mlx, void *mlx_win)
{
    if (mlx_win)
        mlx_destroy_window(mlx, mlx_win);
    exit(0);
}

int	ft_close(int keycode, void *mlx, void *mlx_win)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx, mlx_win);
		cleanup_and_exit(mlx, mlx_win);
	}
	return (0);
}

void resize_window(void *mlx, void **win, int new_width, int new_height) {
    mlx_destroy_window(mlx, *win);
    *win = mlx_new_window(mlx, new_width, new_height, "Resized Window");
}

int	ft_message()
{
	puts("Resize Detector");
	return (0);
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

	mlx_hook(mlx_win, 2, 1, ft_close, mlx);
	mlx_hook(mlx_win, 22, 1<<17, ft_message, mlx);

	draw_hexagon(mlx, mlx_win, 200, 256, 120, ft_trgb(0, 255, 255, 255));
	draw_hexagon(mlx, mlx_win, 300, 556, 50, ft_trgb(0, 255, 255, 255));
	ft_draw_square(mlx_win, &img, 700, 500, 250, ft_trgb(0, 255, 0, 0));
	ft_draw_square(mlx_win, &img, 578, 50, 50, ft_trgb(0, 255, 0, 255));
	ft_draw_square(mlx_win, &img, 890, 200, 38, ft_trgb(0, 143, 201, 255));


	ft_draw_specific(mlx_win, &img, 303, 608, 161, ft_trgb(0, 165, 32, 25));
	ft_draw_specific(mlx_win, &img, 603, 858, 100, ft_trgb(0, 215, 45, 109));
	ft_draw_specific(mlx_win, &img, 867, 550, 254, ft_trgb(0, 194, 176, 120));
	ft_draw_specific(mlx_win, &img, 800, 470, 121, ft_trgb(0, 234, 137, 154));

	ft_draw_triangle(mlx_win, &img, 1250, 198, 13, ft_trgb(0, 244, 169, 0));
	ft_draw_triangle(mlx_win, &img, 358, 140, 135, ft_trgb(0, 175, 43, 30));
	ft_draw_triangle(mlx_win, &img, 1242, 465, 56, ft_trgb(0, 228, 160, 16));
	ft_draw_triangle(mlx_win, &img, 493, 769, 85, ft_trgb(0, 109, 101, 82));
	sleep(2);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	resize_window(mlx, &mlx_win, 1024, 768);
	puts("True");
}

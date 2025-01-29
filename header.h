/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:52:09 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/29 18:00:02 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_ITER 100
# define WIDTH 700
# define HEIGHT 700

typedef struct complex_number
{
	double	real;
	double	img;
}			t_complex;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		(*set);
	t_complex	c;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct all
{
	t_vars	*vars;
	t_data	*img;
}			t_all;

void		ft_print(char *s);
t_complex	ft_pow2(t_complex x);
int			close_program(t_vars *vars);
int			ft_rgb(int r, int g, int b);
double		ft_isnumber(char *s, int flag);
t_complex	ft_add(t_complex x, t_complex y);
void		tricorn(t_data *img, double zoom);
void		mandelbrot(t_data *img, double zoom);
void		julia(t_data *img, t_complex c, double zoom);
int			ft_handle_keypress(int keycode, t_vars *vars);
int			ft_mouse_hook(int button, int x, int y, t_all *ptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif

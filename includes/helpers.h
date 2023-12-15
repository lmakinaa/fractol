/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:30:33 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/15 16:24:57 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h> // to remove
# include <math.h>
# include <stdarg.h>
# include <unistd.h>

# define ERROR_MESSAGE "Usage: ./fractol <model>\n\n\
Available models are:\n\t - mandelbrot\n\t - julia\n"
# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define MAX_ITER 30

typedef struct s_imgdata
{
	void	*obj;
	char	*beg_addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_imgdata;

typedef struct s_program
{
	double		max_value;
	int			max_iter;
	char		*model;
	t_imgdata	img;
	void		*mlx;
	void		*win;
	double		view_x;
	double		view_y;
	double		zoom_scale;
}	t_program;

typedef struct s_complex_number
{
	double	r;
	double	i;
}				t_comp;

int				key_res(int key, t_program *main);
int				mouse_res(int keycode, int x, int y, t_program *main);
void			improved_pixel_put(t_imgdata img, int x, int y, int color);
int				trgb_converter(int t, int r, int g, int b);
unsigned char	get_color(int trgb, int color);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr(long long n, char format);
int				ft_printf(const char *mainstr, ...);
int				ft_atoi(const char *str);
int				ft_putaddr(void *ptr);
int				ft_puthex(unsigned int n, char *base);
size_t			ft_numbase_len(unsigned long long n);
void			program_init(t_program *fractol);
void			program_rendering(t_program *fractol);
double			scaling_down(double unscaled_num, double new_min, double new_max, t_program *fractol);
t_comp			comp_square(t_comp c);
void			program_data_init(t_program *fractol);
void			program_events_init(t_program *fractol);
double			color_mapping(double unscaled_num, double min, double max);
int				closing(t_program *fractol);
void			mandelbrot(int x, int y, t_program *fractol);

#endif
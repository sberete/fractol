#include "fractol.h"

void	fractol_init(t_data *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		malloc_error();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (fractol->win == NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		malloc_error();
	}
}
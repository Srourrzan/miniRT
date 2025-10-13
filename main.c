#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "minirt.h"

//create ft_puts that prints the passed string to the terminal, use ft_printf

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
  printf("r init value = %d\n", r);
  printf("r value after << 24 = %d\n", r << 24);
  return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void *param)
{
  uint32_t 		x;
  uint32_t		y;
  uint32_t	color;
  t_wndw	*wnd = param;

  x = 0;
  while(x < wnd->image->width)
	{
	  y = 0;
	  while(y < wnd->image->height)
		{
		  	color = ft_pixel(
						   rand() % 0xFF,
						   rand() % 0xFF,
						   rand() % 0xFF,
						   rand() % 0xFF
						   );
			printf("color = %d\n", color);
		  	mlx_put_pixel(wnd->image, x, y, color);
		  y++;
		}
	  x++;
	}
}

void ft_hook(void *param)
{
	t_wndw	*wnd = param;

	if (mlx_is_key_down(wnd->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(wnd->mlx);
	if (mlx_is_key_down(wnd->mlx, MLX_KEY_UP))
	  wnd->image->instances[0].y -= 5;
	if (mlx_is_key_down(wnd->mlx, MLX_KEY_DOWN))
	  wnd->image->instances[0].y += 5;
	if (mlx_is_key_down(wnd->mlx, MLX_KEY_LEFT))
	  wnd->image->instances[0].x -= 5;
	if (mlx_is_key_down(wnd->mlx, MLX_KEY_RIGHT))
	  wnd->image->instances[0].x += 5;
}

int32_t main()
{
	t_wndw			*wnd;

	wnd = ft_init_wndw();
	if (!wnd)
	  return (1);
	if (mlx_image_to_window(wnd->mlx, wnd->image, 0, 0) == -1)
	{
		mlx_close_window(wnd->mlx);
		mlx_terminate(wnd->mlx);
		free(wnd);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (3);
	}
	printf("here\n");
	mlx_put_pixel(wnd->image, 3, 3, 0xFF0000FF);
	mlx_loop_hook(wnd->mlx, ft_randomize, wnd);
	mlx_loop_hook(wnd->mlx, ft_hook, wnd);
	mlx_loop(wnd->mlx);
	mlx_delete_image(wnd->mlx, wnd->image);
	mlx_close_window(wnd->mlx);
	mlx_terminate(wnd->mlx);
	free(wnd);
	return (0);
}

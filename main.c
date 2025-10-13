#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "minirt.h"

//create ft_puts that prints the passed string to the terminal, use ft_printf

/* void ft_randomize(void *param) */
/* { */
/*   uint32_t 		x; */
/*   uint32_t		y; */
/*   uint32_t	color; */
/*   t_wndw	*wnd = param; */

/*   x = 0; */
/*   while(x < wnd->image->width) */
/* 	{ */
/* 	  y = 0; */
/* 	  while(y < wnd->image->height) */
/* 		{ */
/* 		  	color = ft_pixel( */
/* 						   rand() % 0xFF, */
/* 						   rand() % 0xFF, */
/* 						   rand() % 0xFF, */
/* 						   rand() % 0xFF */
/* 						   ); */
/* 			printf("color = %d\n", color); */
/* 		  	mlx_put_pixel(wnd->image, x, y, color); */
/* 		  y++; */
/* 		} */
/* 	  x++; */
/* 	} */
/* } */

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
	t_color		c1;
	t_color		c2;
	int32_t		pc1;
	int32_t		pc2;

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
	c1 = init_color(1.5, 0.5, 0, 1);
	c2 = init_color(0, 0.5, 0, 1);
	pc1 = color_to_pixel(c1);
	pc2 = color_to_pixel(c2);
	mlx_put_pixel(wnd->image, 3, 3, pc1);
	mlx_put_pixel(wnd->image, 10, 10, pc2);
	mlx_loop_hook(wnd->mlx, ft_hook, wnd);
	mlx_loop(wnd->mlx);
	mlx_delete_image(wnd->mlx, wnd->image);
	mlx_close_window(wnd->mlx);
	mlx_terminate(wnd->mlx);
	free(wnd);
	return (0);
}

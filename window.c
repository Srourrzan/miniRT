#include <stdio.h>
#include <stdlib.h>
#include "minirt.h"

t_wndw	*ft_init_wndw()
{
	t_wndw			*wnd;
	mlx_t			*mlx;
	mlx_image_t		*image;

	wnd = malloc(sizeof(t_wndw));
	if (!wnd)
	  	return (NULL);
	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (!mlx)
	{
	  	printf("%s\n", mlx_strerror(mlx_errno));
	  	free(wnd);
	  	return (NULL);
	}
	image = mlx_new_image(mlx, 128, 128);
	if (!image)
	{
	  	mlx_close_window(mlx);
		mlx_terminate(wnd->mlx);
	  	free(wnd);
	  	printf("%s\n", mlx_strerror(mlx_errno));
	  	return (NULL);
	}
	wnd->mlx = mlx;
	wnd->image = image;
	return (wnd);
}

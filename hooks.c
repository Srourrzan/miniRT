#include "minirt.h"

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

#ifndef MINIRT_H
# define MINIRT_H

# include <MLX42/MLX42.h>

# include "color.h"
#include "projectile.h"

# define WIDTH 1280
# define HEIGHT 1024

typedef struct	s_wndw
{
  mlx_t			*mlx;
  mlx_image_t	*image;
  t_env			env;
  t_prjct		prjct;
}				t_wndw;

t_wndw	*ft_init_wndw();

void ft_hook(void *param);

#endif

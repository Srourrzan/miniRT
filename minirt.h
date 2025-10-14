#ifndef MINIRT_H
# define MINIRT_H

# include <MLX42/MLX42.h>

# include "color.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct	s_wndw
{
  mlx_t			*mlx;
  mlx_image_t	*image;
  t_env			env;
  t_prjct		prjct;
}				t_wndw;

t_wndw	*ft_init_wndw();

#endif

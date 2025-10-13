#ifndef MINIRT_H
# define MINIRT_H

# include <MLX42/MLX42.h>

# include "color.h"

# define WIDTH 512
# define HEIGHT 512

typedef struct	s_wndw
{
  mlx_t			*mlx;
  mlx_image_t	*image;
}				t_wndw;

t_wndw	*ft_init_wndw();

#endif

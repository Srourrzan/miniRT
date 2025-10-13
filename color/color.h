#ifndef COLOR_H
# define COLOR_H

//# include "minirt.h"
# include <MLX42/MLX42.h>

typedef struct 	s_color
{
  float rgb[4]; // RGBA
  // for A value, 1 is a full color, 0 is a fully transparent color
}				t_color;

typedef struct	s_canvas
{
  float 	width;
  float 	height;
  t_color	**pixels;
}				t_canvas;

t_canvas	*init_canvas(float width, float height);
void		write_pixel(t_canvas *cnvs, int x, int y, t_color color);

int32_t 	color_ftoi(float f);
int32_t		color_to_pixel(t_color c);
t_color		color_scale(t_color c, float s);
t_color		color_add(t_color c1, t_color c2);
t_color		color_sub(t_color c1, t_color c2);
t_color		color_multi(t_color c1, t_color c2);
t_color		init_color(float red, float green, float blue, float alpha);

#endif

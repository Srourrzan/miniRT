#ifndef COLOR_H
# define COLOR_H

typedef struct 	s_color
{
  float rgb[3];
}				t_color;

t_color color_scale(t_color c, float s);
t_color color_add(t_color c1, t_color c2);
t_color color_sub(t_color c1, t_color c2);
t_color color_multi(t_color c1, t_color c2);
t_color init_color(float red, float green, float blue);

#endif

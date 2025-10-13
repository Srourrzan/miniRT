#include "color.h"
#include <string.h>

t_color init_color(float red, float green, float blue, float alpha)
{
	t_color new;

	memset(&new, 0, sizeof(new));
	new.rgb[0] = red;
	new.rgb[1] = green;
	new.rgb[2] = blue;
	new.rgb[3] = alpha;
	return (new);
}

t_color color_add(t_color c1, t_color c2)
{
	float		red;
	float		green;
	float		blue;
	float		alpha;
  	t_color		new;

	red = c1.rgb[0] + c2.rgb[0];
	green = c1.rgb[1] + c2.rgb[1];
	blue = c1.rgb[2] + c2.rgb[2];
	alpha = c2.rgb[3] + c2.rgb[3];
	new = init_color(red, green, blue, alpha);
	return (new);
}

t_color color_sub(t_color c1, t_color c2)
{
  	t_color new;
	float red;
	float green;
	float blue;
	float alpha;

	red = c1.rgb[0] - c2.rgb[0];
	green = c1.rgb[1] - c2.rgb[1];
	blue = c1.rgb[2] - c2.rgb[2];
	alpha = c1.rgb[3] - c2.rgb[3];
	new = init_color(red, green, blue, alpha);
	return (new);
}

int32_t	color_to_pixel(t_color c)
{
  int32_t r;
  int32_t g;
  int32_t b;
  int32_t a;
  
  r = color_ftoi(c.rgb[0]);
  g = color_ftoi(c.rgb[1]);
  b = color_ftoi(c.rgb[2]);
  a = color_ftoi(c.rgb[3]);
  return (r << 24 | g << 16 | b << 8 | a);
}

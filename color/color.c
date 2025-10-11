#include "color.h"
#include <string.h>

t_color init_color(float red, float green, float blue)
{
	t_color new;

	memset(&new, 0, sizeof(new));
	new.rgb[0] = red;
	new.rgb[1] = green;
	new.rgb[2] = blue;
	return (new);
}

t_color color_add(t_color c1, t_color c2)
{
  	t_color new;
	float red;
	float green;
	float blue;

	red = c1.rgb[0] + c2.rgb[0];
	green = c1.rgb[1] + c2.rgb[1];
	blue = c1.rgb[2] + c2.rgb[2];
	new = init_color(red, green, blue);
	return (new);
}

t_color color_sub(t_color c1, t_color c2)
{
  	t_color new;
	float red;
	float green;
	float blue;

	red = c1.rgb[0] - c2.rgb[0];
	green = c1.rgb[1] - c2.rgb[1];
	blue = c1.rgb[2] - c2.rgb[2];
	new = init_color(red, green, blue);
	return (new);
}

t_color pixel_color(t_canvas *cnv, int x, int y)
{
	t_color pxl;

	pxl = cnv->pixels[y][x];
	return (pxl);
}

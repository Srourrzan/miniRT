#include "minirt.h"

t_color color_hadamard_product(t_color c1, t_color c2)
{
  	t_color new;
	float r;
	float g;
	float b;
	float a;

	r = c1.rgb[0] * c2.rgb[0];
	g = c1.rgb[1] * c2.rgb[1];
	b = c1.rgb[2] * c2.rgb[2];
	a = c1.rgb[3] * c2.rgb[3];
	new = init_color(r, g, b, a);
	return (new);
}

t_color color_scale(t_color c, float s)
{
  	t_color new;
	float red;
	float green;
	float blue;
	float alpha;

	red = c.rgb[0] * s;
	green = c.rgb[1] * s;
	blue = c.rgb[2] * s;
	alpha = c.rgb[3] * s;
	new = init_color(red, green, blue, alpha);
	return (new);
}

t_color color_multi(t_color c1, t_color c2)
{
	t_color new;
	float red;
	float green;
	float blue;
	float alpha;

	red = c1.rgb[0] * c2.rgb[0];
	green = c1.rgb[1] * c2.rgb[1];
	blue = c1.rgb[2] * c2.rgb[2];
	alpha = c1.rgb[3] * c2.rgb[3];
	new = init_color(red, green, blue, alpha);
	return (new);
}

int32_t color_ftoi(float f)
{
	int32_t ret;

	ret = (int32_t)(f * 255.999);
	return (ret);
}

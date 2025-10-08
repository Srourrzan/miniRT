#include "color.h"

t_color color_hadamard_product(t_color c1, t_color c2)
{
  	t_color new;
	float r;
	float g;
	float b;

	r = c1.rgb[0] * c2.rgb[0];
	g = c1.rgb[1] * c2.rgb[1];
	b = c1.rgb[2] * c2.rgb[2];
	new = init_color(r, g, b);
	return (new);
}

#include <stdlib.h>
#include "minirt.h"

t_canvas *init_canvas(float width, float height)
{
  	int x;
	int y;
	t_canvas *new;

	y = 0;
	x = 0;
	new = malloc(sizeof(t_canvas));
	if (!new)
		return (NULL);
	new->width = width;
	new->height = height;
	new->pixels = malloc(height * sizeof(t_color *));
	if (!new->pixels)
	{
		free(new);
		return (NULL);
	}
	while (y < height)
	{
	  	new->pixels[y] = malloc(width * sizeof(t_color));
	  	if (!new->pixels[y])
	  	{
			//write a looping free function for all previous allocated ys
			free(new->pixels);
			free(new);
			return (NULL);
	  	}
		x = 0;
		while(x < width)
		{
		  new->pixels[y][x] = init_color(0, 0, 0, 0);
			x++;
		}
		y++;
	}
	return (new);
}

void write_pixel(t_canvas *cnvs, int x, int y, t_color color)
{
  	if (x >= 0 && x < cnvs->width
	  	&& y >= 0 && y < cnvs->height)
	  cnvs->pixels[y][x] = color;
}

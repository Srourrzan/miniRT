#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include "minirt.h"

int main()
{
  	t_canvas 	*cnv;
	t_color		red;
	t_color		pxl;
	int i;

	i = 0;
	cnv = init_canvas(10, 20);
	red = init_color(1, 0, 0);
	write_pixel(cnv, 2, 3, red);
	pxl = pixel_color(cnv, 2, 3);
	while(i < 3)
	  {
		if (red.rgb[i] != pxl.rgb[i])
		  printf("unmatch");
		else
		  printf("matching\n");
		i++;
	  }
	return (0);
}

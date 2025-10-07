#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include "color.h"
#include "matrix.h"
#include "ext_math.h"
#include "projectile.h"

void set_tuples(t_tuple *tup, float x, float y, float z, float w)
{
 	tup->p[0] = x;
 	tup->p[1] = y;
	tup->p[2] = z;
	tup->p[3] = w;
}


int main()
{
  t_color c1;
  t_color c2;
  t_color res;

  c1 = init_color(1, 0.2, 0.4);
  c2 = init_color(0.9, 1, 0.1);
  res = color_multi(c1, c2);
  printf("the res rgb(%f, %f, %f)\n", res.rgb[0], res.rgb[1], res.rgb[2]);

	return (0);
}

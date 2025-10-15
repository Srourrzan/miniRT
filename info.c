#include <stdio.h>
#include "matrix.h"
#include "info.h"

void tuple_info(t_tuple tup)
{
  if (tup.is_vect)
	printf("vector: <%f, %f, %f>\n", tup.p[0], tup.p[1], tup.p[2]);
  else
	printf("point: (%f, %f, %f)\n", tup.p[0], tup.p[1], tup.p[2]);
}

void mat_info(void _mat)
{
  
}

void mat4_info(t_mat4 mat)
{
  printf("|%10f|%10f|10%f|%10f|\n", mat.r[0], mat.r[1], mat.r[2], mat.r[3]);
  printf("|%10f|%10f|10%f|%10f|\n", mat.r[4], mat.r[5], mat.r[6], mat.r[7]);
  printf("|%10f|%10f|10%f|%10f|\n", mat.r[8], mat.r[9], mat.r[10], mat.r[11]);
  printf("|%10f|%10f|10%f|%10f|\n", mat.r[12], mat.r[13], mat.r[14], mat.r[15]);
}

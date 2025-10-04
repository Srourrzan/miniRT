#include <stdio.h>
#include "matrix.h"

void tuple_info(t_tuple tup)
{
  if (tup.is_vect)
	printf("tuple is a vector: <%f, %f, %f>\n", tup.p[0], tup.p[1], tup.p[2]);
  else
	printf("tuple is a point: (%f, %f, %f)\n", tup.p[0], tup.p[1], tup.p[2]);
}

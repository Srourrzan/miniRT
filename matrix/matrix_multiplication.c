#include <math.h>
#include "matrix.h"
#include <stddef.h>

float tuple_dot_product(t_tuple t1, t_tuple t2)
{
	float dot_prod;
	
  	if (!t1.is_vect || !t2.is_vect)
		return (-1);
	dot_prod = t1.p[0] * t2.p[0] + t1.p[1] * t2.p[1] +
	  	t1.p[2] * t2.p[2] + t1.p[3] * t2.p[3];
	return (dot_prod);
}

int tuple_cross_product(t_tuple *r_res, t_tuple t1, t_tuple t2)
{
	float x;
	float y;
	float z;

	if (!t1.is_vect || !t2.is_vect)
		return (-1);
	x = t1.p[1] * t2.p[2] - t1.p[2] * t2.p[1];
	y = - t1.p[0] * t2.p[2]  + t1.p[2] * t2.p[0];
	z = t1.p[0] * t2.p[1] - t1.p[1] * t2.p[0];
	*r_res = init_tuple(x, y, z, 0);
	return (0);
}

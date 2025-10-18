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


void	mat4_multiplicaton(t_mat4 *res, t_mat4 *m1_r, t_mat4 *m2_r)
{
  	res->m[0][0] = m1_r->m[0][0] * m2_r->m[0][0] + m1_r->m[0][1] * m2_r->m[1][0] +
		m1_r->m[0][2] * m2_r->m[2][0] + m1_r->m[0][3] * m2_r->m[3][0];
	res->m[0][1] = m1_r->m[0][0] * m2_r->m[0][1] + m1_r->m[0][1] * m2_r->m[1][1] +
		m1_r->m[0][2] * m2_r->m[2][1] + m1_r->m[0][3] * m2_r->m[3][1];
	res->m[0][2] = m1_r->m[0][0] * m2_r->m[0][2] + m1_r->m[0][1] * m2_r->m[1][2] +
		m1_r->m[0][2] * m2_r->m[2][2] + m1_r->m[0][3] * m2_r->m[3][2];
	res->m[0][3] = m1_r->m[0][0] * m2_r->m[0][3] + m1_r->m[0][1] * m2_r->m[1][3] +
		m1_r->m[0][2] * m2_r->m[2][3] + m1_r->m[0][3] * m2_r->m[3][3];
	res->m[1][0] = m1_r->m[1][0] * m2_r->m[0][0] + m1_r->m[1][1] * m2_r->m[1][0] +
		m1_r->m[1][2] * m2_r->m[2][0] + m1_r->m[1][3] * m2_r->m[3][0];
	res->m[1][1] = m1_r->m[1][0] * m2_r->m[0][1] + m1_r->m[1][1] * m2_r->m[1][1] +
		m1_r->m[1][2] * m2_r->m[2][1] + m1_r->m[1][3] * m2_r->m[3][1];
	res->m[1][2] = m1_r->m[1][0] * m2_r->m[0][2] + m1_r->m[1][1] * m2_r->m[1][2] +
		m1_r->m[1][2] * m2_r->m[2][2] + m1_r->m[1][3] * m2_r->m[3][2];
	res->m[1][3] = m1_r->m[1][0] * m2_r->m[0][3] + m1_r->m[1][1] * m2_r->m[1][3] +
		m1_r->m[1][2] * m2_r->m[2][3] + m1_r->m[1][3] * m2_r->m[3][3];
}

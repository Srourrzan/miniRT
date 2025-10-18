#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "matrix.h"

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

t_tuple	mat4_multi_tuple(t_mat4 *m, t_tuple *tup)
{
	t_tuple new;
	float x;
	float y;
	float z;
	float w;
	
    x = m->m[0][0] * tup->p[0] + m->m[0][1] * tup->p[1] + m->m[0][2] * tup->p[2] + m->m[0][3] * tup->p[3];
    y = m->m[1][0] * tup->p[0] + m->m[1][1] * tup->p[1] + m->m[1][2] * tup->p[2] + m->m[1][3] * tup->p[3];
	z = m->m[2][0] * tup->p[0] + m->m[2][1] * tup->p[1] + m->m[2][2] * tup->p[2] + m->m[2][3] * tup->p[3];
	w = m->m[3][0] * tup->p[0] + m->m[3][1] * tup->p[1] + m->m[3][2] * tup->p[2] + m->m[3][3] * tup->p[3];
	new = init_tuple(x, y, z, w);
	return (new);
}

void	mat4_multiplication(t_mat4 *res, t_mat4 *m1_r, t_mat4 *m2_r)
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
	
	res->m[2][0] = m1_r->m[2][0] * m2_r->m[0][0] + m1_r->m[2][1] * m2_r->m[1][0] +
		m1_r->m[2][2] * m2_r->m[2][0] + m1_r->m[2][3] * m2_r->m[3][0];
	res->m[2][1] = m1_r->m[2][0] * m2_r->m[0][1] + m1_r->m[2][1] * m2_r->m[1][1] +
		m1_r->m[2][2] * m2_r->m[2][1] + m1_r->m[2][3] * m2_r->m[3][1];
	res->m[2][2] = m1_r->m[2][0] * m2_r->m[0][2] + m1_r->m[2][1] * m2_r->m[1][2] +
		m1_r->m[2][2] * m2_r->m[2][2] + m1_r->m[2][3] * m2_r->m[3][2];
	res->m[2][3] = m1_r->m[2][0] * m2_r->m[0][3] + m1_r->m[2][1] * m2_r->m[1][3] +
		m1_r->m[2][2] * m2_r->m[2][3] + m1_r->m[2][3] * m2_r->m[3][3];
	
	res->m[3][0] = m1_r->m[3][0] * m2_r->m[0][0] + m1_r->m[3][1] * m2_r->m[1][0] +
		m1_r->m[3][2] * m2_r->m[2][0] + m1_r->m[3][3] * m2_r->m[3][0];
	res->m[3][1] = m1_r->m[3][0] * m2_r->m[0][1] + m1_r->m[3][1] * m2_r->m[1][1] +
		m1_r->m[3][2] * m2_r->m[2][1] + m1_r->m[3][3] * m2_r->m[3][1];
	res->m[3][2] = m1_r->m[3][0] * m2_r->m[0][2] + m1_r->m[3][1] * m2_r->m[1][2] +
		m1_r->m[3][2] * m2_r->m[2][2] + m1_r->m[3][3] * m2_r->m[3][2];
	res->m[3][3] = m1_r->m[3][0] * m2_r->m[0][3] + m1_r->m[3][1] * m2_r->m[1][3] +
		m1_r->m[3][2] * m2_r->m[2][3] + m1_r->m[3][3] * m2_r->m[3][3];
}

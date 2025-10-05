#include <stdio.h>
#include <string.h>
#include "ext_math.h"
#include "matrix.h"
#include "info.h"

/*
 * This file contains tuple immutable math operations,
 * Where each function returns a new tuple.
 */

t_tuple tuple_neg(t_tuple *tup)
{
  	t_tuple new;
	float x;
	float y;
	float z;
	float w;
	
    x = 0 - tup->p[0];
	y = 0 - tup->p[1];
	z = 0 - tup->p[2];
	w = 0 - tup->p[3];
	new = init_tuple(x, y, z, w);
	printf("the result of negative tuple: ");
	tuple_info(new);
	return (new);
}

t_tuple tuple_add(t_tuple t1, t_tuple t2)
{
  	t_tuple new;
	float x;
	float y;
	float z;
	float w;

	x = t1.p[0] + t2.p[0];
    y = t1.p[1] + t2.p[1];
	z = t1.p[2] + t2.p[2];
	w = t1.p[3] + t2.p[3];
	new = init_tuple(x, y, z, w);
	printf("the result of added tuples: ");
	tuple_info(new);
	return (new);
}

t_tuple tuple_sub(t_tuple t1, t_tuple t2)
{
  	t_tuple new;
	float x;
	float y;
	float z;
	float w;

	x = t1.p[0] - t2.p[0];
    y = t1.p[1] - t2.p[1];
	z = t1.p[2] - t2.p[2];
	w = t1.p[3] - t2.p[3];
	new = init_tuple(x, y, z, w);
	printf("the result of sub tuples: ");
	tuple_info(new);
	return (new);
}

t_tuple tuple_scale(t_tuple t, float sc)
{
  	t_tuple new;
  	float x;
  	float y;
  	float z;
  	float w;

	x = t.p[0] * sc;
	y = t.p[1] * sc;
	z = t.p[2] * sc;
	w = t.p[3] * sc;
	new = init_tuple(x, y, z, w);
	printf("the result of scaling tuple: ");
	tuple_info(new);
	return (new);
}

t_tuple tuple_norm(t_tuple t)
{
  	t_tuple new;
	float x;
	float y;
	float z;
	float w;

    x = t.p[0] / tuple_magnitude(t);
	y = t.p[1] / tuple_magnitude(t);
	z = t.p[2] / tuple_magnitude(t);
	w = t.p[3] / tuple_magnitude(t);
	new = init_tuple(x, y, z, w);
	return (new);
}


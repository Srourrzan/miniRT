#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "info.h"
#include "ext_math.h"

void set_tuples(t_tuple *tup, float x, float y, float z, float w)
{
 	tup->p[0] = x;
 	tup->p[1] = y;
	tup->p[2] = z;
	tup->p[3] = w;
}


int main()
{
  	t_tuple p;
  	t_tuple v;

	p = init_tuple(0.0, 0.0, 0.0, 0.0);
	v = init_tuple(1, -2, 3, 0.0);
	tuple_info(p);
	tuple_info(v);
	ft_sub_tuple(p, v);
	return (0);
}

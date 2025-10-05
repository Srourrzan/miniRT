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
  	t_tuple a;
	t_tuple b;
    float dot;

	a = init_tuple(1, 2, 3, 1);
	b = init_tuple(2, 3, 4, 0);
	dot = tuple_dot_product(a, b);
	if (dot < 0)
	  {
		printf("cannot operate dot product on points\n");
		return (1);
	  }
    printf("The dot product of two tuples: ");
	tuple_info(a);
	tuple_info(b);
	printf(" is: %f\n", dot);
	return (0);
}

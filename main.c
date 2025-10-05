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
  	t_tuple t;
	float mag;
	t_tuple norm;

	t = init_tuple(1, 2, 3, 0);
    norm = tuple_norm(t);
	printf("normalized vector of the vector ");
	tuple_info(t);
	printf(" is ");
	tuple_info(norm);
	mag = tuple_magnitude(norm);
	printf("magnitude of norm is: ");
	printf(" = %f\n", mag);
	return (0);
}

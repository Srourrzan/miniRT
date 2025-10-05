#include "matrix.h"
#include <string.h>
#include <stdio.h>
#include "info.h"
#include <math.h>

float tuple_magnitude(t_tuple t)
{
	float mag;

	mag = sqrtf(t.p[0] * t.p[0] + t.p[1] * t.p[1]
				+ t.p[2] * t.p[2]);// * t.p[3] * t.p[3]);
	return (mag);
}

t_tuple init_tuple(float x, float y, float z, float w)
{
	t_tuple new;

	memset(&new, 0, sizeof(new));
	new.p[0] = x;
	new.p[1] = y;
	new.p[2] = z;
	new.p[3] = w;
	if (w == 0)
		new.is_vect = 1;
	return (new);
}


#include "ext_math.h"

int ft_float_equal(float a, float b)
{
  	if (ft_abs(a - b) < EPSILON)
		return (1);
  	return (0);
}

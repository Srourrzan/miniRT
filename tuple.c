#include "matrix.h"
#include <string.h>
#include <stdio.h>
#include "info.h"

t_tuple ft_add_tuple(t_tuple t1, t_tuple t2)
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

t_tuple ft_sub_tuple(t_tuple t1, t_tuple t2)
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

void ft_neg_tuple(t_tuple *tup)
{
	tup->p[0] = 0 - tup->p[0];
	tup->p[1] = 0 - tup->p[1];
	tup->p[2] = 0 - tup->p[2];
	tup->p[3] = 0 - tup->p[3];
	printf("the result of negative tuple: ");
	tuple_info(*tup);
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

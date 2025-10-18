#include "matrix.h"

float mat_det(void *_base_mat)
{
  t_mat *base;
  float det;

  base = (t_mat *)_base_mat;
  if (base->det)
	det = base->det(_base_mat);
  return (det);
}

float mat2_det(void *self)
{
  t_mat2 *mat;
  float det;

  mat = (t_mat2 *)self;
  det = mat->m[0][0] * mat->m[1][1] - mat->m[0][1] * mat->m[1][0];
  return (det);
}

#include "matrix.h"
#include <stdio.h>

float mat_cofactor(void *_base_mat, void *sub_mat, int row, int col)
{
  t_mat *base;
  float cofactor;

  cofactor = 0;
  base = (t_mat *)_base_mat;
  if(base->cofactor)
	cofactor = base->cofactor(_base_mat, sub_mat, row, col);
  return (cofactor);
}

float mat3_cofactor(void *self, void *sub_mat, int row, int col)
{
  float cofactor;
  float minor;

  minor = mat_minor(self, sub_mat, row, col);
  if ((row + col) % 2 == 0)
	cofactor = minor;
  else
	cofactor = -1 * minor;
  return (cofactor);
}

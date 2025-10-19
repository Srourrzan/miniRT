#include "matrix.h"

float mat_minor(void *_base_mat, void *sub_mat, int row, int col)
{
  t_mat *base;
  float minorf;

  minorf = 0;
  base = (t_mat *)_base_mat;
  if (base->minor)
	minorf = base->minor(_base_mat, sub_mat, row, col);
  return (minorf);
}

float mat3_minor(void *self, void *sub_mat, int row, int col)
{
  float det;
  
  ft_sub_mat(self, sub_mat, row, col);
  det = mat_det(sub_mat);
  return (det);
}

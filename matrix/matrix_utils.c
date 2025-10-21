#include "matrix.h"

int mat_isinvertable(void *base_mat)
{
  float det;
  t_mat	*mat;

  mat = (t_mat *)base_mat;
  det = mat_det(base_mat);
  mat->det_value = det;
  if (det != 0)
	{
	  mat->is_invertable = 1;
	  return (1);
	}
  mat->is_invertable = 0;
  return (0);
}

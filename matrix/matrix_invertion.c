#include "matrix.h"
#include "info.h"
#include <stdio.h>

int inverse_mat(void *base_mat, void *inv_mat)
{
  t_mat *mat;
  int status;

  status = 0;
  mat = (t_mat *)base_mat;
  if (mat->inverse)
	status = mat->inverse(base_mat, inv_mat);
  return (status);
}

int mat4_inverse(void *self, void *invmat)
{
  int i;
  int j;
  t_mat4 *mat;
  t_mat4  *inv_mat;
  t_mat3 submat;

  mat = (t_mat4 *)self;
  inv_mat = (t_mat4 *)invmat;
  if (mat->mat.is_invertable == 0)
	return (0);
  printf("starting to invert\n");
  i = 0;
  while (i < 4)
	{
	  j = 0;
	  while (j < 4)
		{
		  submat = init_mat3();
		  ft_sub_mat(mat, &submat, i, j);
		  inv_mat->m[j][i] = mat_cofactor(mat, &submat, i, j) / mat->mat.det_value;
		  j++;
		}
	  i++;
	}
  return (1);
}

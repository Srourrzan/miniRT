#include "matrix.h"
#include "info.h"
#include <stdio.h>

void	ft_sub_mat(void *_base_mat, void *sub_mat, int row, int col)
{
  t_mat *base;

  base = (t_mat *)_base_mat;
  if (base->sub_mat)
	base->sub_mat(_base_mat, sub_mat, row, col);
}

void	mat4_submat(void *self, void *sub_mat, int row, int col)
{
  t_mat4 *mat;
  t_mat3 *submat;
  int i;
  int j;
  int k;
  int l;

  mat = (t_mat4 *)self;
  submat = (t_mat3 *)sub_mat;
  i = 0;
  k = 0;
  while (i < 4)
	{
	  j = 0;
	  l = 0;
	  while (j < 4)
		{
		  if (i == row || j == col)
			{
			  j++;
			  continue;
			}
		  submat->m[k][l] = mat->m[i][j];
		  j++;
		  l++;
		  if (l > 2)
			k++;
		}
	  i++;
	}
}

void	mat3_submat(void *self, void *sub_mat, int row, int col)
{
  t_mat3 *mat;
  t_mat2 *submat;
  int i;
  int j;
  int k;
  int l;

  mat = (t_mat3 *)self;
  submat = (t_mat2 *)sub_mat;
  mat_info(mat);
  i = 0;
  k = 0;
  while (i < 3)
	{
	  j = 0;
	  l = 0;
	  while (j < 3)
		{
		  if (i == row || j == col)
			{
			  j++;
			  continue;
			}
		  printf("mat[%i][%i] = %f\n", i, j, mat->m[i][j]);
		  submat->m[k][l] = mat->m[i][j];
		  j++;
		  l++;
		  if (l > 1)
			k++;
		}
	  i++;
	}
}

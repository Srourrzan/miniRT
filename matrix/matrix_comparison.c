#include "matrix.h"
#include <MLX42/MLX42.h>

// can we use polymorphism for these functions?

int32_t mat4_equality(t_mat4 *r_m1, t_mat4 *r_m2)
{
  int i;
  int j;

  i = 0;
  while (i < 4)
	{
	  j = 0;
	  while (j < 4)
		{
		  if (r_m1->m[i][j] != r_m2->m[i][j])
			return (0);
		  j++;
		}
	  i++;
	}
  return (1);
}

int32_t mat3_equality(t_mat3 *r_m1, t_mat3 *r_m2)
{
  int i;
  int j;

  i = 0;
  while (i < 3)
	{
	  j = 0;
	  while (j < 3)
		{
		  if (r_m1->m[i][j] != r_m2->m[i][j])
			return (0);
		  j++;
		}
	  i++;
	}
  return (1);
}

int32_t mat2_equality(t_mat2 *r_m1, t_mat2 *r_m2)
{
  int i;
  int j;

  i = 0;
  while (i < 2)
	{
	  j = 0;
	  while (j < 2)
		{
		  if (r_m1->m[i][j] != r_m2->m[i][j])
			return (0);
		  j++;
		}
	  i++;
	}
  return (1);
}

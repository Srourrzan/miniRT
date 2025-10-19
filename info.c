#include <stdio.h>
#include "matrix.h"
#include "info.h"

void tuple_info(t_tuple tup)
{
  if (tup.is_vect)
	printf("vector: <%f, %f, %f>\n", tup.p[0], tup.p[1], tup.p[2]);
  else
	printf("point: (%f, %f, %f)\n", tup.p[0], tup.p[1], tup.p[2]);
}

void mat_info(void *_base_mat)
{
  t_mat *base;
  
  base = (t_mat *)_base_mat;
  if (base->info)
	  base->info(_base_mat);
}

void mat4_info(void *self)
{
  t_mat4 *mat;

  mat = (t_mat4 *)self;
  printf("|%10f|%10f|%10f|%10f|\n", mat->m[0][0], mat->m[0][1], mat->m[0][2], mat->m[0][3]);
  printf("|%10f|%10f|%10f|%10f|\n", mat->m[1][0], mat->m[1][1], mat->m[1][2], mat->m[1][3]);
  printf("|%10f|%10f|%10f|%10f|\n", mat->m[2][0], mat->m[2][1], mat->m[2][2], mat->m[2][3]);
  printf("|%10f|%10f|%10f|%10f|\n", mat->m[3][0], mat->m[3][1], mat->m[3][2], mat->m[3][3]);
}

void mat3_info(void *self)
{
  t_mat3 *mat;

  mat = (t_mat3 *)self;
  //printf("%s: m[0][0] =  %f\n", __func__, mat->m[0][0]);
  printf("|%10f|%10f|%10f|\n", mat->m[0][0], mat->m[0][1], mat->m[0][2]);
  printf("|%10f|%10f|%10f|\n", mat->m[1][0], mat->m[1][1], mat->m[1][2]);
  printf("|%10f|%10f|%10f|\n", mat->m[2][0], mat->m[2][1], mat->m[2][2]);
}

void mat2_info(void *self)
{
  t_mat2 *mat;

  mat = (t_mat2 *)self;
  printf("|%10f|%10f|\n", mat->m[0][0], mat->m[0][1]);
  printf("|%10f|%10f|\n", mat->m[1][0], mat->m[1][1]);
}

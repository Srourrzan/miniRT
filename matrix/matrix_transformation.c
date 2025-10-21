#include "matrix.h"

t_mat4 mat_translation(float x, float y, float z)
{
  t_mat4 iden;

  iden = iden_mat4();
  iden.m[0][3] = x;
  iden.m[1][3] = y;
  iden.m[2][3] = z;
  return (iden);
}

t_mat4 mat_scale(float x, float y, float z)
{
  t_mat4 iden;

  iden = iden_mat4();
  iden.m[0][0] = x;
  iden.m[1][1] = y;
  iden.m[2][2] = z;
  return (iden);
}

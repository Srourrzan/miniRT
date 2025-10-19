#include "matrix.h"
#include "minirt.h"
#include "info.h"
#include <string.h>

t_mat4 init_mat4()
{
  t_mat4 new;

  memset(&new, 0, sizeof(new));
  new.mat.info = mat4_info;
  new.mat.det = mat4_det;
  new.mat.sub_mat = mat4_submat;
  new.mat.minor = mat4_minor;
  new.mat.cofactor = mat4_cofactor;
  return (new);
}

t_mat3 init_mat3()
{
  t_mat3 new;
  
  memset(&new, 0, sizeof(new));
  new.mat.info = mat3_info;
  new.mat.det = mat3_det;
  new.mat.sub_mat = mat3_submat;
  new.mat.minor = mat3_minor;
  new.mat.cofactor = mat3_cofactor;
  return (new);
}

t_mat2 init_mat2()
{
  t_mat2 new;
  
  memset(&new, 0, sizeof(new));
  new.mat.info = mat2_info;
  new.mat.det = mat2_det;
  new.mat.sub_mat = NULL;
  new.mat.minor = NULL;
  new.mat.cofactor = NULL;
  return (new);
}

t_mat4 iden_mat4()
{
  t_mat4 new;

  new = init_mat4();
  new.m[0][0] = 1;
  new.m[1][1] = 1;
  new.m[2][2] = 1;
  new.m[3][3] = 1;
  return (new);
}

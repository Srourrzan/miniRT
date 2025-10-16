#include "matrix.h"
#include "minirt.h"
#include "info.h"
#include <string.h>

t_mat4 init_mat4()
{
  t_mat4 new;

  memset(&new, 0, sizeof(new));
  new.mat.info = mat4_info;
  return (new);
}

t_mat3 init_mat3()
{
  t_mat3 new;
  memset(&new, 0, sizeof(new));
  new.mat.info = mat3_info;
  return (new);
}

t_mat2 init_mat2()
{
  t_mat2 new;
  memset(&new, 0, sizeof(new));
  new.mat.info = mat2_info;
  return (new);
}

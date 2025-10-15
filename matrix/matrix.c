#include "matrix.h"
#include "minirt.h"
#include "info.h"

t_mat4 init_mat4()
{
  t_mat4 new;

  memset(&new, 0, sizeof(new));
  new.mat.info = mat4_info;
  return (new);
}

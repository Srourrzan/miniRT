#include "matrix.h"

void set_mat_transpose(t_mat4 *trans, t_mat4 *m)
{
  trans->m[0][0] = m->m[0][0];
  trans->m[0][1] = m->m[1][0];
  trans->m[0][2] = m->m[2][0];
  trans->m[0][3] = m->m[3][0];
  trans->m[1][0] = m->m[0][1];
  trans->m[1][1] = m->m[1][1];
  trans->m[1][2] = m->m[2][1];
  trans->m[1][3] = m->m[3][1];
  trans->m[2][0] = m->m[0][2];
  trans->m[2][1] = m->m[1][2];
  trans->m[2][2] = m->m[2][2];
  trans->m[2][3] = m->m[3][2];
  trans->m[3][0] = m->m[0][3];
  trans->m[3][1] = m->m[1][3];
  trans->m[3][2] = m->m[2][3];
  trans->m[3][3] = m->m[3][3];
}

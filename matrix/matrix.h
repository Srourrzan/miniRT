#ifndef MATRIX_H
# define MATRIX_H

# define NAME_SIZE 32


typedef struct	s_tuple
{
  //
  char		name[NAME_SIZE];
  float	p[4];
  int is_vect;
  void	(*set_data)(); //will create later, to create one for all math types
}				t_tuple;

typedef struct 	s_mat4
{
  float r[16];
  float m[4][4];
}				t_mat4;

typedef struct	s_mat3
{
  float m[3][3];
}				t_mat3;

typedef struct	s_mat2
{
  float m[2][2];
}				t_mat2;

void		tuple_neg_set(t_tuple *tup);
void		tuple_scale_set(t_tuple *t, float sc);
void		tuple_sub_set(t_tuple *t1, t_tuple t2);
void		tuple_add_set(t_tuple *t1, t_tuple t2);

t_tuple		tuple_norm(t_tuple t); //normalize a vector
t_tuple		tuple_neg(t_tuple *tup);
t_tuple		tuple_scale(t_tuple t, float sc);
t_tuple		tuple_sub(t_tuple t1, t_tuple t2);
t_tuple		tuple_add(t_tuple t1, t_tuple t2);

float		tuple_magnitude(t_tuple t);
t_tuple		init_tuple(float x, float y, float z, float w);

float		tuple_dot_product(t_tuple t1, t_tuple t2);
int			tuple_cross_product(t_tuple *r_res,t_tuple t1, t_tuple t2);

void 		matrix_viz(t_mat4 mat);

#endif

#ifndef MATRIX_H
# define MATRIX_H

# include <MLX42/MLX42.h>

# define NAME_SIZE 32


typedef struct	s_tuple
{
  //
  char		name[NAME_SIZE];
  float	p[4];
  int is_vect;
  void	(*set_data)(); //will create later, to create one for all math types
}				t_tuple;

typedef struct 	s_mat
{
  void	(*info)(void *self);
  float	(*det)(void *self);
  void	(*sub_mat)(void *self, void *sub_mat, int row, int col);
  float	(*minor)(void *self, void *sub_mat, int row, int col);
  float (*cofactor)(void *self, void *sub_mat, int row, int col);
  // if we needed comparing equality for mat3 or mat2 then we will define one here
}				t_mat;

typedef struct 	s_mat4
{
  t_mat	mat;
  float m[4][4];
}				t_mat4;

typedef struct	s_mat3
{
  t_mat	mat;
  float m[3][3];
}				t_mat3;

typedef struct	s_mat2
{
  t_mat	mat;
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
t_tuple		mat4_multi_tuple(t_mat4 *m, t_tuple *tup);
int			tuple_cross_product(t_tuple *r_res,t_tuple t1, t_tuple t2);
void		mat4_multiplication(t_mat4 *res, t_mat4 *m1_r, t_mat4 *m2_r);

t_mat4		init_mat4();
t_mat4		iden_mat4();
t_mat3		init_mat3();
t_mat2		init_mat2();

int32_t		mat4_equality(t_mat4 *r_m1, t_mat4 *r_m2);
void		set_mat_transpose(t_mat4 *trans, t_mat4 *m);

float		mat_det(void *_base_mat);
float		mat2_det(void *self);
float		mat3_det(void *self);
float		mat4_det(void *self);

void		ft_sub_mat(void *_base_mat, void *sub_mat, int row, int col);
void		mat4_submat(void *self, void *sub_mat, int row, int col);
void		mat3_submat(void *self, void *sub_mat, int row, int col);

float		mat_minor(void *_base_mat, void *sub_mat, int row, int col);
float		mat3_minor(void *self, void *sub_mat, int row, int col);
float		mat4_minor(void *self, void *sub_mat, int row, int col);

float		mat_cofactor(void *_base_mat, void *sub_mat, int row, int col);
float		mat3_cofactor(void *self, void *sub_mat, int row, int col);
float		mat4_cofactor(void *self, void *sub_mat, int row, int col);

#endif

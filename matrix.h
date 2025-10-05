#ifndef MATRIX_H
# define MATRIX_H

# define NAME_SIZE 32


typedef struct	s_tuple
{
  char		name[NAME_SIZE];
  float	p[4];
  int is_vect;
  void	(*set_data)(); //will create later, to create one for all math types
}				t_tuple;

t_tuple ft_add_tuple(t_tuple t1, t_tuple t2);
t_tuple ft_sub_tuple(t_tuple t1, t_tuple t2);
t_tuple init_tuple(float x, float y, float z, float w);

#endif

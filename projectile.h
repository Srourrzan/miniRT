#ifndef PROJECTILE_H
# define PROJECTILE_H

# include "matrix.h"

typedef struct 	s_prjct
{
  	t_tuple position; //point
  	t_tuple velocity; //vector
}				t_prjct;

typedef struct	s_env
{
  	t_tuple gravity; //vector
  	t_tuple wind; //vector
}				t_env;

t_prjct tick(t_prjct proj, t_env env);
t_env init_env(t_tuple grav, t_tuple wind);
t_prjct init_projectile(t_tuple position, t_tuple velocity);

#endif

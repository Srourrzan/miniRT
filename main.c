#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include "matrix.h"
#include "ext_math.h"
#include "projectile.h"

void set_tuples(t_tuple *tup, float x, float y, float z, float w)
{
 	tup->p[0] = x;
 	tup->p[1] = y;
	tup->p[2] = z;
	tup->p[3] = w;
}


int main()
{
	t_tuple 	position;
	t_tuple 	velocity;
	t_tuple 	grav;
	t_tuple 	wind;
	t_prjct 	proj;
	t_env 		env;
	int i;

	i = 0;
  	position = init_tuple(0, 1, 0, 1);
	velocity = init_tuple(1, 1, 0, 0);
	tuple_scale_set(&velocity, 1);
	printf("velocity after scaling: ");
	tuple_info(velocity);
	grav = init_tuple(0, -0.1, 0, 0);
	wind = init_tuple(-0.01, 0, 0, 0);
	proj = init_projectile(position, velocity);
	env = init_env(grav, wind);
	while(proj.position.p[1] > 0)
	  {
		proj = tick(proj, env);
	 	i++;
	  }
	printf("proj position: ");
	tuple_info(proj.position);
	printf("number of ticks = %d\n", i);
	return (0);
}

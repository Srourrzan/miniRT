#include "projectile.h"
#include <unistd.h>
#include <string.h>

t_env init_env(t_tuple grav, t_tuple wind)
{
 	 t_env new;

	memset(&new, 0, sizeof(new));
	new.gravity = init_tuple(grav.p[0], grav.p[1],
							  grav.p[2], grav.p[3]);
	new.wind = init_tuple(wind.p[0], wind.p[1],
							  wind.p[2], wind.p[3]);
	return (new);
}

t_prjct init_projectile(t_tuple position, t_tuple velocity)
{
	t_prjct new;

	memset(&new, 0, sizeof(new));
	new.position = init_tuple(position.p[0], position.p[1],
							  position.p[2], position.p[3]);
	new.velocity = init_tuple(velocity.p[0], velocity.p[1],
							  velocity.p[2], velocity.p[3]);
	return (new);
}

t_prjct tick(t_prjct proj, t_env env)
{
  	t_prjct new;
	t_tuple tmp;
	t_tuple position;
	t_tuple velocity;

	position = tuple_add(proj.position, proj.velocity);
	tmp = tuple_add(proj.velocity, env.gravity);
	velocity = tuple_add(tmp, env.wind);
	new = init_projectile(position, velocity);
	return (new);
}

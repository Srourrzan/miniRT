#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "info.h"
#include "matrix.h"
#include "minirt.h"
#include "projectile.h"

//create ft_puts that prints the passed string to the terminal, use ft_printf

void ft_fill_green(void *param)
{
  uint32_t 		x;
  uint32_t		y;
  t_color		green;
  uint32_t	color;
  t_wndw	*wnd = param;

  x = 0;
  green = init_color(0, 0.6, 0, 1);
  while(x < wnd->image->width)
	{
	  y = 0;
	  while(y < wnd->image->height)
		{
		  color = color_to_pixel(green);
		  	mlx_put_pixel(wnd->image, x, y, color);
		  y++;
		}
	  x++;
	}
}

t_prjct new_projectile() //hard_coded
{
  	t_prjct projc;
  	t_tuple	position;
	t_tuple	velocity;

	position = init_tuple(0, 600, 0, 1);
	velocity = init_tuple(1, 1.8, 0, 0);
	velocity = tuple_norm(velocity);
	velocity = tuple_scale(velocity, 11.25);
	projc.position = position;
	projc.velocity = velocity;
	return (projc);
}

t_env new_env() //hard_coded
{
  t_env		env;
  t_tuple	gravity;
  t_tuple	wind;

  gravity = init_tuple(0, -0.1, 0, 0);
  wind = init_tuple(-0.01, 0, 0, 0);
  env = init_env(gravity, wind);
  return (env);
}

void display_projectile(void *param)
{
  	t_wndw	*wnd = param;
	t_color c;
	int32_t clr;
	float	x;
	float	y;

	c = init_color(0, 0.6, 0.2, 1);
	clr = color_to_pixel(c);
	x = wnd->prjct.position.p[0];
	y = wnd->image->height - wnd->prjct.position.p[1];
	while ((x < wnd->image->width && x >= 0)
		   && (y < wnd->image->height && y >= 0))
	{
	  	mlx_put_pixel(wnd->image, x, y, clr);
	  	wnd->prjct = tick(wnd->prjct, wnd->env);
		x = wnd->prjct.position.p[0];
		y = wnd->image->height - wnd->prjct.position.p[1];
	}
}

void fill_mat4(t_mat4 *r_mat)
{
  r_mat->m[0][0] = 3;
  r_mat->m[0][1] = -9;
  r_mat->m[0][2] = 7;
  r_mat->m[0][3] = 3;
  
  r_mat->m[1][0] = 3;
  r_mat->m[1][1] = -8;
  r_mat->m[1][2] = 2;
  r_mat->m[1][3] = -9;
  
  r_mat->m[2][0] = -4;
  r_mat->m[2][1] = 4;
  r_mat->m[2][2] = 4;
  r_mat->m[2][3] = 1;
  
  r_mat->m[3][0] = -6;
  r_mat->m[3][1] = 5;
  r_mat->m[3][2] = -1;
  r_mat->m[3][3] = 1;
}

void fill_mat4_(t_mat4 *r_mat)
{
  r_mat->m[0][0] = 8;
  r_mat->m[0][1] = 2;
  r_mat->m[0][2] = 2;
  r_mat->m[0][3] = 2;
  
  r_mat->m[1][0] = 3;
  r_mat->m[1][1] = -1;
  r_mat->m[1][2] = 7;
  r_mat->m[1][3] = 0;
  
  r_mat->m[2][0] = 7;
  r_mat->m[2][1] = 0;
  r_mat->m[2][2] = 5;
  r_mat->m[2][3] = 4;
  
  r_mat->m[3][0] = 6;
  r_mat->m[3][1] = -2;
  r_mat->m[3][2] = 0;
  r_mat->m[3][3] = 5;
}

#ifdef MAT
int32_t main()
{
	t_mat4 a;
	t_mat4 transa;
	t_mat4 inva;
	t_mat4 invb;
	t_mat4 transb;

	a = iden_mat4();
	inva = init_mat4();
	transa = init_mat4();
	invb = init_mat4();
	transb = init_mat4();
	fill_mat4(&a);
	printf("a:\n");
	mat_info(&a);
	set_mat_transpose(&transa, &a);
	printf("trans:\n");
	mat_info(&transa);
	if (mat_isinvertable(&transa) == 1)
    	inverse_mat(&transa, &inva);
	else
	  {
		printf("trasa is no invertable");
		return (0);
	  }
	printf("inverse:\n");
	mat_info(&inva);
	//==============================================
	printf("a:\n");
	mat_info(&a);
	//	printf("a is invertable = %d\n", )
	if (mat_isinvertable(&a) == 1)
    	inverse_mat(&invb, &a);
	else
	  {
		printf("a is no invertable");
		return (0);
	  }
	printf("inverse:\n");
	mat_info(&invb);
	set_mat_transpose(&transb, &invb);
	printf("transb:\n");
	mat_info(&transb);
	//mat4_multiplication(&b, &a, &inva);
	/* printf("mat b:\n"); */
	/* mat_info(&b); */
	return (0);
}
# else
int32_t main()
{
	t_wndw *wnd;
  
	wnd = ft_init_wndw();
	if (!wnd)
	  return (1);
	wnd->prjct = new_projectile();
	wnd->env = new_env();
	if (mlx_image_to_window(wnd->mlx, wnd->image, 0, 0) == -1)
	{
		mlx_close_window(wnd->mlx);
		mlx_terminate(wnd->mlx);
		free(wnd);
		printf("%s\n", mlx_strerror(mlx_errno));
		return (3);
	}
	mlx_loop_hook(wnd->mlx, display_projectile, wnd);
	mlx_loop_hook(wnd->mlx, ft_hook, wnd);
	mlx_delete_image(wnd->mlx, wnd->image);
	mlx_close_window(wnd->mlx);
	mlx_terminate(wnd->mlx);
	free(wnd);
	return (0);;
}
#endif

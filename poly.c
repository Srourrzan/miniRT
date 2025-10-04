#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char const* barbieSound(void) {return "Love and imagination can change the world.";}
char const* supermanSound(void) {return "Up, up, and away!";}

typedef struct	s_toy
{
  char const *(*makeSound)();
}				t_toy;

void makeSound(t_toy *self)
{
  printf("%s\n", self->makeSound());
}

t_toy *createBarbie()
{
  t_toy *barbie = malloc(sizeof(t_toy));
  barbie->makeSound = barbieSound;
  return (barbie);
}

//resource: https://hackernoon.com/a-practical-guide-to-dynamic-polymorphism-in-c-programming?utm_source=chatgpt.com

int main(void)
{
  	int i;
	t_toy *toy1;
  	t_toy *toy2;
  	t_toy *toy3;
  	t_toy *toys[3];

	i = 0;
  	toy1 = malloc(sizeof(t_toy));
  	if (!toy1)
		return (1);
  	toy2 = malloc(sizeof(t_toy));
  	if (!toy2)
		return (1);
  	toy3 = malloc(sizeof(t_toy));
  	if (!toy3)
		return (1);
  	toy1->name = "Barbie";
	toy2->name = "Barbie";
	toy3->name = "Superman";
	toys[0] = toy1;
	toys[1] = toy2;
	toys[2] = toy3;
	while (i < 3)
	{
	  if (strcmp(toys[i]->name, "Barbie"))
		  printf("%s: %s\n", toys[i]->name, barbieSound());
	  if (strcmp(toys[i]->name, "Superman"))
		  printf("%s: %s\n", toys[i]->name, supermanSound());
		i++;
	}
	free(toy1);
	free(toy2);
	free(toy3);
	return (0);
}

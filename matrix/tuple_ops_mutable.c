#include <stdio.h>
#include <string.h>
#include "ext_math.h"
#include "matrix.h"
#include "info.h"

void tuple_neg_set(t_tuple *tup)
{
	tup->p[0] = 0 - tup->p[0];
	tup->p[1] = 0 - tup->p[1];
	tup->p[2] = 0 - tup->p[2];
	tup->p[3] = 0 - tup->p[3];
}

void tuple_add_set(t_tuple *t1, t_tuple t2)
{
	t1->p[0] = t1->p[0] + t2.p[0];
    t1->p[1] = t1->p[1] + t2.p[1];
	t1->p[2] = t1->p[2] + t2.p[2];
	t1->p[3] = t1->p[3] + t2.p[3];
}

void tuple_sub_set(t_tuple *t1, t_tuple t2)
{
	t1->p[0] = t1->p[0] - t2.p[0];
    t1->p[1] = t1->p[1] - t2.p[1];
	t1->p[2] = t1->p[2] - t2.p[2];
	t1->p[3] = t1->p[3] - t2.p[3];
}

void tuple_scale_set(t_tuple *t, float sc)
{
	t->p[0] = t->p[0] * sc;
	t->p[1] = t->p[1] * sc;
	t->p[2] = t->p[2] * sc;
	t->p[3] = t->p[3] * sc;
}

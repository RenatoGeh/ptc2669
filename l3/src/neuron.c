#include "neuron.h"

#include <stdlib.h>
#include <string.h>

neuron_t* new_neuron(int n_pa) {
  neuron_t *val;
  int i;

  val = (neuron_t*) malloc(sizeof(neuron_t));
  val->n = n_pa;
  val->w = (double*) malloc(n_pa*sizeof(double));
  val->y = (double*) malloc(n_pa*sizeof(double));
  val->v = 0;
  val->y[0] = 1;

  memset(val->w, 0, n_pa*sizeof(double));
}

double compute_field(neuron_t *n) {
  int i, s;
  double v = 0, *w, *y;
  w = n->w, y = n->y;
  for (i=0,s=n->n;i<s;++i)
    v += w[i]*y[i];
  n->v = v;
  return v;
}

void free_neuron(neuron_t *r) {
  free(r->w);
  free(r->y);
  free (r);
}

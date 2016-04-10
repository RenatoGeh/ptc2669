#include "nnet.h"

#include <stdlib.h>

#include "neuron.h"

layer_t* new_layer(int c, int pl) {
  layer_t* lay;
  int i;

  lay = (layer_t*) malloc(sizeof(layer_t));
  lay->n = c;

  lay->set = (neuron_t**) malloc(c*sizeof(neuron_t*));

  for (i=0;i<c;++i) {
    neuron_t* j = new_neuron(pl);
    lay->set[i] = j;
  }

  return lay;
}

void free_layer(layer_t *r) {
  int i, s;
  neuron_t **set;

  set = r->set;
  for (i=0,s=r->n;i<s;++i)
    free_neuron(set[i]);
  free(r->set);

  free(r);
}

nnet_t* new_nnet(double *x, int n_x, double *d, int n_d, int n_l, int n_c) {
  nnet_t *net;
  int i, pl = 0;

  net = (nnet_t*) malloc(sizeof(nnet_t));
  net->x = (double*) malloc(n_x*sizeof(double));
  net->d = (double*) malloc(n_d*sizeof(double));
  net->n_x = n_x, net->n_d = n_d;

  net->l = (layer_t**) malloc(n_l*sizeof(layer_t));
  net->n_l = n_l;

  /* Input neurons. */
  net->l[0] = new_layer(n_c, n_x);
  --n_l;
  for (i=1;i<n_l;++i)
    net->l[i] = new_layer(n_c, net->l[i-1]->n);

  return net;
}

void free_nnet(nnet_t *r) {
  int i, nl;

  free(r->x);
  free(r->d);

  nl = r->n_l;
  for (i=0;i<nl;++i)
    free_layer(r->l[i]);
  free(r->l);

  free(r);
}

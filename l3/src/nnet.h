#ifndef NNET_H_
#define NNET_H_

#include "neuron.h"

/** Layer of neurons.
 */
typedef struct __layer_t layer_t;
struct __layer_t {
  /* Ordered set of neurons. */
  neuron_t **set;
  /* Number of neurons in this layer. */
  int n;
};

/** Constructs a new layer with parameter:
 * int c  : number of neurons in this layer
 * int pl : number of neurons in the previous layer; if input neuron then equal to |x|
 */
layer_t* new_layer(int c, int pl);

/** Destroys layer. */
void free_layer(layer_t *r);

/** Neural network structure.
 */
typedef struct __nnet_t nnet_t;
struct __nnet_t {
  /* Input training sample. */
  double *x;
  /* Size of x. */
  int n_x;
  /* Desired output sample. */
  double *d;
  /* Size of d. */
  int n_d;
  /* Neuron layers. */
  layer_t **l;
  /* Number of layers. */
  int n_l;
};

/** Creates new Neural Network with the following parameters:
 * double *x   : input training sample
 * int     n_x : size of x
 * double *d   : desired response sample
 * int     n_d : size of d
 * int     n_l : number of hidden layers
 * int     n_c : number of neurons in each layer
 */
nnet_t* new_nnet(double *x, int n_x, double *d, int n_d, int n_l, int n_c);

/** Destroys neural network. */
void free_nnet(nnet_t *r);

#endif

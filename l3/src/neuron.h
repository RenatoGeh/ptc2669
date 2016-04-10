#ifndef NEURON_H_
#define NEURON_H_

/** Neuron data structure.
 * w[0] = b (bias)
 * y[0] = 1
 */
typedef struct __neuron_t neuron_t;
struct __neuron_t {
  /* Number of weights (and connecting neighbours). */
  int n;
  /* Weights. */
  double *w;
  /* Local outputs. */
  double *y;
  /* Induced local field (SUM_j w_ji*y_i). */
  double v;
};

/** Constructs a new neuron.
 * int n_pa : number of connected neurons from the previous layer
 */
neuron_t* new_neuron(int n_pa);

/** Destroys neuron. */
void free_neuron(neuron_t *r);

/** Computes the induced field SUM_j w_ji*y_i.
 */
double compute_field(neuron_t *n);

#endif

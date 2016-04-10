#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STEP_SIZE 0.01

double lms();

/**
 * Args:
 *  [1] n samples
 *  [2] b bias
 *  [3] uni (1) or bidimensional (2)
 */
int main(int argc, char *args[]) {
  double w;

  w = lms();

  printf("Resulting line:\nf(x)=%.4fx + b\n", w);

  return 0;
}

double lms() {
  double *x, *d;
  double e, w=0;
  double y;
  int i, n;

  scanf("%d ", &n);

  x = (double*) malloc(n*sizeof(double));
  d = (double*) malloc(n*sizeof(double));

  for (i=0;i<n;++i)
    scanf("%lf ", &x[i]);

  for (i=0;i<n;++i)
    scanf("%lf ", &d[i]);

  for (i=0;i<n;++i) {
    y = w*x[i];
    e = d[i] - y;
    w = w + 2*STEP_SIZE*e*x[i];
  }

  return w;
}

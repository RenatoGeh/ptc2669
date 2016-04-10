#include <stdio.h>

#include "nnet.h"
#include "neuron.h"

int main(int argc, char *argv[]) {
  nnet_t *network;
  int x[][] = {
    {0.1, 6.8, -3.5, 2.0, 4.1, 3.1, -0.8, 0.9, 5.0, 3.9},
    {1.1, 7.1, -4.1, 2.7, 2.8, 5.0, -1.3, 1.2, 6.4, 4.0}
  };
  int d[] = {2, 2, 1, 2, 1, 2, 1, 2, 2, 2};

  network = new_nnet(

  return 0;
}

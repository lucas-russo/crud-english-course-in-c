#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int is_empty(Node* node) {
  return node == NULL;
}

Node* initialize_tree() {
  return NULL;
}

void initialize_random_seed() {
  srand(time(NULL));
}

int generate_registration() {
  int lower_bound = 10000;
  int upper_bound = 99999;
  int random_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
  return random_number;
}

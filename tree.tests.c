#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int test_is_empty() {
  Node * empty_node = NULL;
  Node node;
  node.student.registration = 42702;
  node.left = NULL;
  node.right = NULL;

  if (is_empty(empty_node)) printf("Test for empty node: Passed\n");
  else printf("Test for empty node: Failed\n");

  if (!is_empty( & node)) printf("Test for not empty node: Passed\n");
  else printf("Test for not empty node: Failed\n");

  return 0;
}

int test_initialize_tree() {
  Node * tree = initialize_tree();

  if (is_empty(tree)) printf("Test initialize tree: Passed\n");
  else printf("Test initialize tree: Failed\n");

  free(tree);

  return 0;
}

int test_generate_registration() {
  initialize_random_seed();

  int i = 0;
  for (i = 0; i < 10; i++) {
    int random_number = generate_registration();
    printf("randon registration %d: %d\n", i, random_number);
    if (random_number < 10000 || random_number > 99999) {
      printf("\nTest generate_registration: Failed\n");
      return 1;
    }
  }

  printf("\nTest generate_registration: Passed\n");
  return 0; // O teste passou
}

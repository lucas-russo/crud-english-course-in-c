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

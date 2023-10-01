#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int test_number = 0;

void run_test(char* test_name[25], int test);

int main(int argc, char* argv[]) {
  run_test("is_empty()", test_is_empty());
  run_test("initialize_tree()", test_initialize_tree());
  run_test("free_node()", test_free_node());
  run_test("generate_registration()", test_generate_registration());
  run_test("create_node()", test_create_node());

  return 0;
}

void run_test(char* test_name[25], int test) {
  test_number++;
  printf("\nTEST %d -> %s ", test_number, test_name);
  if (test == 0)
    printf(
        "run with out problems\n\n - - - - - - - - - - - - - - - - - - - - - - "
        "- - - - - - - - - \n\n");
  sleep(1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "tree.h"

int test_number = 0;

void run_test(char* test_name[25], int test) {
  test_number++;
  printf("\nTEST %d -> %s ", test_number, test_name);
  if (test == 0)
    printf(
        "run with out problems\n\n - - - - - - - - - - - - - - - - - - - - - - "
        "- - - - - - - - - \n\n");
  sleep(1);
}

int test_constants(void) {
  int i;

  printf("Class Levels:\n");
  for (i = 0; i < 3; i++) {
    printf("%d: %s\n", i, class_level_types[i]);

    if (strcmp(class_level_types[i], "Beginner") == 0)
      printf("Class Level is correct: Beginner\n");
    else if (strcmp(class_level_types[i], "Intermediate") == 0)
      printf("Class Level is correct: Intermediate\n");
    else if (strcmp(class_level_types[i], "Advanced") == 0)
      printf("Class Level is correct: Advanced\n");
    else
      printf("Class Level is incorrect\n");
  }

  printf("\nLanguages:\n");
  for (i = 0; i < 4; i++) {
    printf("%d: %s\n", i, language_types[i]);

    // Comparar com a string esperada
    if (strcmp(language_types[i], "English") == 0)
      printf("Language is correct: English\n");
    else if (strcmp(language_types[i], "Spanish") == 0)
      printf("Language is correct: Spanish\n");
    else if (strcmp(language_types[i], "French") == 0)
      printf("Language is correct: French\n");
    else if (strcmp(language_types[i], "Italian") == 0)
      printf("Language is correct: Italian\n");
    else
      printf("Language is incorrect\n");
  }

  return 0;
}

int test_is_empty() {
  Node* empty_node = NULL;
  Node* node = (Node*)malloc(sizeof(Node));

  node->student.registration = 42702;
  node->left = NULL;
  node->right = NULL;

  if (is_empty(empty_node))
    printf("Test for empty node: Passed\n");
  else
    printf("Test for empty node: Failed\n");

  if (!is_empty(node))
    printf("Test for not empty node: Passed\n");
  else
    printf("Test for not empty node: Failed\n");

  free(node);

  return 0;
}

int test_initialize_tree() {
  Node* tree = initialize_tree();

  if (is_empty(tree))
    printf("Test initialize tree: Passed\n");
  else
    printf("Test initialize tree: Failed\n");

  free(tree);

  return 0;
}

int test_free_node() {
  Node* node1 = (Node*)malloc(sizeof(Node));
  node1->student.registration = 12702;
  strcpy(node1->student.name, "Alice");
  strcpy(node1->student.class_level, class_level_types[2]);
  strcpy(node1->student.language, language_types[0]);
  node1->left = NULL;
  node1->right = NULL;

  Node* node2 = (Node*)malloc(sizeof(Node));
  node2->student.registration = 24270;
  strcpy(node2->student.name, "Bob");
  strcpy(node2->student.class_level, class_level_types[0]);
  strcpy(node2->student.language, language_types[1]);
  node2->left = NULL;
  node2->right = NULL;

  Node* root = (Node*)malloc(sizeof(Node));
  root->student.registration = 34272;
  strcpy(root->student.name, "Charlie");
  strcpy(root->student.class_level, class_level_types[1]);
  strcpy(root->student.language, language_types[2]);
  root->left = node1;
  root->right = node2;

  free_node(root);

  printf("Test free_node: Passed\n");
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
  return 0;
}

int test_create_node() {
  Student student = {generate_registration(), "Alice", class_level_types[2],
                     language_types[0]};
  Node* left = create_node(student, NULL, NULL);
  Node* right = create_node(student, NULL, NULL);
  Node* root = create_node(student, left, right);

  if (root == NULL || root->left != left || root->right != right) {
    printf("Test create_node: Failed\n");
    return 1;
  }

  free_node(left);
  free_node(right);
  free_node(root);

  printf("Test create_node: Passed\n");
  return 0;
}

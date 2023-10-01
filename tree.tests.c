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

void print_student_names(Node* node) {
  if (node == NULL) return;

  print_student_names(node->left);
  printf("%s\n", node->student.name);
  print_student_names(node->right);
}

int is_tree_alphabetical(Node* node) {
  if (node == NULL) return 1;

  if (node->left != NULL &&
      strcmp(node->student.name, node->left->student.name) <= 0)
    return 0;

  if (node->right != NULL &&
      strcmp(node->student.name, node->right->student.name) >= 0)
    return 0;

  if (!is_tree_alphabetical(node->left) || !is_tree_alphabetical(node->right))
    return 0;

  return 1;
}

int test_include_student(void) {
  Node* root = initialize_tree();

  Student student1 = {generate_registration(), "Zoe", class_level_types[0],
                      language_types[2]};
  Student student2 = {generate_registration(), "Alice", class_level_types[2],
                      language_types[0]};
  Student student3 = {generate_registration(), "Charlie", class_level_types[1],
                      language_types[2]};
  Student student4 = {generate_registration(), "Yasmine", class_level_types[1],
                      language_types[0]};
  Student student5 = {generate_registration(), "Anna", class_level_types[0],
                      language_types[1]};
  Student student6 = {generate_registration(), "Bob", class_level_types[1],
                      language_types[3]};
  Student student7 = {generate_registration(), "Catherine",
                      class_level_types[2], language_types[0]};
  Student student8 = {generate_registration(), "Henry", class_level_types[2],
                      language_types[1]};
  Student student9 = {generate_registration(), "Xander", class_level_types[1],
                      language_types[1]};
  Student student10 = {generate_registration(), "Zach", class_level_types[2],
                       language_types[3]};

  root = include_student(root, student1);
  root = include_student(root, student2);
  root = include_student(root, student3);
  root = include_student(root, student4);
  root = include_student(root, student5);
  root = include_student(root, student6);
  root = include_student(root, student7);
  root = include_student(root, student8);
  root = include_student(root, student9);
  root = include_student(root, student10);

  printf("Names inserted in the tree:\n");
  print_student_names(root);
  printf("\n");

  if (is_tree_alphabetical(root)) {
    printf("Test include_student: Passed\n");
    return 0;
  } else {
    printf("Test include_student: Failed\n");
    return 1;
  }
}

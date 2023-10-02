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

int test_free_tree() {
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

  free_tree(root);

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
  Student student;
  student.registration = generate_registration();
  strncpy(student.name, "Alice", sizeof(student.name));
  strncpy(student.class_level, class_level_types[2],
          sizeof(student.class_level));
  strncpy(student.language, language_types[0], sizeof(student.language));

  Node* left = create_node(student, NULL, NULL);
  Node* right = create_node(student, NULL, NULL);
  Node* root = create_node(student, left, right);

  if (root == NULL || root->left != left || root->right != right) {
    printf("Test create_node: Failed\n");
    return 1;
  }

  free_tree(root);

  printf("Test create_node: Passed\n");
  return 0;
}

void print_student_names(Node* node) {
  if (node == NULL) return;
  print_student_names(node->left);
  printf("%s\n", node->student.name);
  printf("%s\n", node->student.class_level);
  printf("%s\n", node->student.language);
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

  Student student1;
  student1.registration = generate_registration();
  strncpy(student1.name, "Zoe", sizeof(student1.name));
  strncpy(student1.class_level, class_level_types[0],
          sizeof(student1.class_level));
  strncpy(student1.language, language_types[2], sizeof(student1.language));

  Student student2;
  student2.registration = generate_registration();
  strncpy(student2.name, "Alice", sizeof(student2.name));
  strncpy(student2.class_level, class_level_types[2],
          sizeof(student2.class_level));
  strncpy(student2.language, language_types[0], sizeof(student2.language));

  Student student3;
  student3.registration = generate_registration();
  strncpy(student3.name, "Charlie", sizeof(student3.name));
  strncpy(student3.class_level, class_level_types[1],
          sizeof(student3.class_level));
  strncpy(student3.language, language_types[2], sizeof(student3.language));

  Student student4;
  student4.registration = generate_registration();
  strncpy(student4.name, "Yasmine", sizeof(student4.name));
  strncpy(student4.class_level, class_level_types[1],
          sizeof(student4.class_level));
  strncpy(student4.language, language_types[0], sizeof(student4.language));

  Student student5;
  student5.registration = generate_registration();
  strncpy(student5.name, "Anna", sizeof(student5.name));
  strncpy(student5.class_level, class_level_types[0],
          sizeof(student5.class_level));
  strncpy(student5.language, language_types[1], sizeof(student5.language));

  Student student6;
  student6.registration = generate_registration();
  strncpy(student6.name, "Bob", sizeof(student6.name));
  strncpy(student6.class_level, class_level_types[1],
          sizeof(student6.class_level));
  strncpy(student6.language, language_types[3], sizeof(student6.language));

  Student student7;
  student7.registration = generate_registration();
  strncpy(student7.name, "Catherine", sizeof(student7.name));
  strncpy(student7.class_level, class_level_types[2],
          sizeof(student7.class_level));
  strncpy(student7.language, language_types[0], sizeof(student7.language));

  Student student8;
  student8.registration = generate_registration();
  strncpy(student8.name, "Henry", sizeof(student8.name));
  strncpy(student8.class_level, class_level_types[2],
          sizeof(student8.class_level));
  strncpy(student8.language, language_types[1], sizeof(student8.language));

  Student student9;
  student9.registration = generate_registration();
  strncpy(student9.name, "Xander", sizeof(student9.name));
  strncpy(student9.class_level, class_level_types[1],
          sizeof(student9.class_level));
  strncpy(student9.language, language_types[1], sizeof(student9.language));

  Student student10;
  student10.registration = generate_registration();
  strncpy(student10.name, "Zach", sizeof(student10.name));
  strncpy(student10.class_level, class_level_types[2],
          sizeof(student10.class_level));
  strncpy(student10.language, language_types[3], sizeof(student10.language));

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
    free_tree(root);
    return 0;
  } else {
    printf("Test include_student: Failed\n");
    return 1;
  }
}

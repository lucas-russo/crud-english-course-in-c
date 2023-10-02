#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "tree.h"

int is_empty(Node* node) { return node == NULL; }

Node* initialize_tree() { return NULL; }

void free_node(Node* node) {
  if (node == NULL) return;

  free_node(node->left);
  free_node(node->right);
  free(node);
}

void initialize_random_seed() { srand(time(NULL)); }

int generate_registration() {
  int lower_bound = 10000;
  int upper_bound = 99999;
  int random_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
  return random_number;
}

Node* create_node(Student student, Node* left, Node* right) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  if (!new_node) {
    perror("Memory allocation error");
    exit(1);
  }

  Student new_student;

  new_student.registration = generate_registration;
  strncpy(new_student.name, student.name, sizeof(new_student.name));
  strncpy(new_student.class_level, student.class_level,
          sizeof(new_student.class_level));
  strncpy(new_student.language, student.language, sizeof(new_student.language));

  new_node->student = new_student;
  new_node->left = left;
  new_node->right = right;

  return new_node;
}

Node* include_student(Node* node, Student student) {
  if (!node) return create_node(student, NULL, NULL);

  int comparison = strcmp(student.name, node->student.name);

  if (comparison <= 0)
    node->left = include_student(node->left, student);
  else
    node->right = include_student(node->right, student);

  return node;
}

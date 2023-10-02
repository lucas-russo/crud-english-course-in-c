#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "tree.h"

Node* read_file_and_insert_into_tree(Node* root) {
  FILE* file = fopen("students.txt", "r");
  if (file == NULL) {
    printf("Unable to open the file.\n");
    return root;
  }

  char line[100];
  Student student;

  while (fgets(line, sizeof(line), file) != NULL) {
    line[strcspn(line, "\n")] = '\0';

    strncpy(student.name, line, sizeof(student.name));

    student.registration = generate_registration();

    if (fgets(line, sizeof(line), file) != NULL) {
      line[strcspn(line, "\n")] = '\0';
      strncpy(student.class_level, line, sizeof(student.class_level));
    }
    if (fgets(line, sizeof(line), file) != NULL) {
      line[strcspn(line, "\n")] = '\0';
      strncpy(student.language, line, sizeof(student.language));
    }

    root = include_student(root, student);
  }

  fclose(file);

  if (!is_tree_alphabetical(root)) exit(1);
printf("SYSTEM LOADED SUCCESSFULLY\n");
sleep(2);
  return root;
}

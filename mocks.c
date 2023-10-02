#include <stdlib.h>
#include <string.h>

#include "mocks.h"

Student student1;
Student student2;
Student student3;
Student student4;
Student student5;
Student student6;
Student student7;
Student student8;
Student student9;
Student student10;

void initialize_students_mocks() {
  student1.registration = generate_registration();
  strncpy(student1.name, "Zoe", sizeof(student1.name));
  strncpy(student1.class_level, class_level_types[0],
          sizeof(student1.class_level));
  strncpy(student1.language, language_types[2], sizeof(student1.language));

  student2.registration = generate_registration();
  strncpy(student2.name, "Alice", sizeof(student2.name));
  strncpy(student2.class_level, class_level_types[2],
          sizeof(student2.class_level));
  strncpy(student2.language, language_types[0], sizeof(student2.language));

  student3.registration = generate_registration();
  strncpy(student3.name, "Charlie", sizeof(student3.name));
  strncpy(student3.class_level, class_level_types[1],
          sizeof(student3.class_level));
  strncpy(student3.language, language_types[2], sizeof(student3.language));

  student4.registration = generate_registration();
  strncpy(student4.name, "Yasmine", sizeof(student4.name));
  strncpy(student4.class_level, class_level_types[1],
          sizeof(student4.class_level));
  strncpy(student4.language, language_types[0], sizeof(student4.language));

  student5.registration = generate_registration();
  strncpy(student5.name, "Anna", sizeof(student5.name));
  strncpy(student5.class_level, class_level_types[0],
          sizeof(student5.class_level));
  strncpy(student5.language, language_types[1], sizeof(student5.language));

  student6.registration = generate_registration();
  strncpy(student6.name, "Bob", sizeof(student6.name));
  strncpy(student6.class_level, class_level_types[1],
          sizeof(student6.class_level));
  strncpy(student6.language, language_types[3], sizeof(student6.language));

  student7.registration = generate_registration();
  strncpy(student7.name, "Catherine", sizeof(student7.name));
  strncpy(student7.class_level, class_level_types[2],
          sizeof(student7.class_level));
  strncpy(student7.language, language_types[0], sizeof(student7.language));

  student8.registration = generate_registration();
  strncpy(student8.name, "Henry", sizeof(student8.name));
  strncpy(student8.class_level, class_level_types[2],
          sizeof(student8.class_level));
  strncpy(student8.language, language_types[1], sizeof(student8.language));

  student9.registration = generate_registration();
  strncpy(student9.name, "Xander", sizeof(student9.name));
  strncpy(student9.class_level, class_level_types[1],
          sizeof(student9.class_level));
  strncpy(student9.language, language_types[1], sizeof(student9.language));

  student10.registration = generate_registration();
  strncpy(student10.name, "Zach", sizeof(student10.name));
  strncpy(student10.class_level, class_level_types[2],
          sizeof(student10.class_level));
  strncpy(student10.language, language_types[3], sizeof(student10.language));
}

void free_all_students_mocks() {
  memset(&student1, 0, sizeof(Student));
  memset(&student2, 0, sizeof(Student));
  memset(&student3, 0, sizeof(Student));
  memset(&student4, 0, sizeof(Student));
  memset(&student5, 0, sizeof(Student));
  memset(&student6, 0, sizeof(Student));
  memset(&student7, 0, sizeof(Student));
  memset(&student8, 0, sizeof(Student));
  memset(&student9, 0, sizeof(Student));
  memset(&student10, 0, sizeof(Student));
}

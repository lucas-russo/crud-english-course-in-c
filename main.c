#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "tree.h"
#include "file.h"

void clear_console(void);
int run_all_test(void);
void main_menu(void);

int main(int argc, char* argv[]) {
  //if (run_all_tests() != 0) exit(1);
  
  main_menu();

  return 0;
}

void clear_console() { system("cls"); }

int run_all_tests() {
	printf("\nRUNING ALL TESTS: \n\n");
  run_test("constants", test_constants());
  run_test("is_empty()", test_is_empty());
  run_test("initialize_tree()", test_initialize_tree());
  run_test("free_tree()", test_free_tree());
  run_test("generate_registration()", test_generate_registration());
  run_test("create_node()", test_create_node());
  run_test("include_student()", test_include_student());
  run_test("list_all_students()", test_list_all_students());
  
  return 0;
}

void main_menu() {
	
  Node * students = initialize_tree();
  students = read_file_and_insert_into_tree(students);
  
    int opcao = 0, sair = 0;

    do {
    	clear_console();
    	
        printf("\n(1) List students");
        printf("\n(2) Add student");
        printf("\n(3) Change student");
        printf("\n(4) Consult student");
        printf("\n(5) Delete student");
        printf("\n(6) Exit");
        printf("\n\nChoose option: ");
        scanf("%d", & opcao);

        switch (opcao) {
        case 1:
        	printf("\nREGISTERED STUDENTS: \n\n");
			list_all_students(students);
            getch();
            break;
        case 2:
            printf("\nADD NEW STUDENT: \n\n");
            getch();
            break;
        case 3:
            printf("\nCHANGE STUDENT: \n\n");
            getch();
            break;
        case 4:
            printf("\nCONSULT STUDENT: \n\n");
            getch();
            break;
        case 5:
           	printf("\nDELETE STUDENT: \n\n");
            getch();
            break;
        case 6:
          	printf("\n(6) EXIT");
            sair = 1;
            break;
        default:
            printf("\nINVALID OPTION! \n");
            getch();
            sair = 0;
        }
    } while (!sair);
}

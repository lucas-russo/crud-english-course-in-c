typedef struct student {
  int registration;
  char name[25];
  char class_level[12];
  char language[10];
} Student;

typedef struct tree_node {
  Student student;
  struct tree_node* right;
  struct tree_node* left;
} Node;

/* DONE */
void run_test(char* test_name[25], int test);

int is_empty(Node* node);
int test_is_empty(void);

Node* initialize_tree(void);
int test_initialize_tree(void);

void free_tree(Node* node);
int test_free_tree();

void initialize_random_seed(void);
int generate_registration(void);
int test_generate_registration(void);

void list_all_students(Node* node);
int test_list_all_students(void);

/* Russo - to do: */
Node* search_student(char* name[25]);
int test_search_student(void);

void show_student(Student student);
int test_search_student(void);

/* Hermano DONE */
Node* create_node(Student student, Node* left, Node* right);
int test_create_node(void);

Node* include_student(Node* node, Student student);
void print_student_names(Node* node);
int is_tree_alphabetical(Node* node);
int test_include_student(void);

/* Sergio - to do: */
Node* change_student(char* name[25]);
int test_change_student(void);

Node* delete_student(char* name[25]);
int test_delete_student(void);


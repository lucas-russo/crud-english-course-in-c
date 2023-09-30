typedef struct student {
  int registration;
  char name[25];
  char class_level[12];
  char language[10];
} Student;

typedef struct tree_node {
  Student student;
  struct tree_node * right;
  struct tree_node * left;
} Node;

int is_empty(Node * node);
int test_is_empty(void);

Node * initialize_tree(void);
int test_initialize_tree(void);

void initialize_random_seed(void);
int generate_registration(void);
int test_generate_registration(void);



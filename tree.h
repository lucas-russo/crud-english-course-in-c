typedef struct student {
  int registration;
  char name[25];
  char class [12];
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
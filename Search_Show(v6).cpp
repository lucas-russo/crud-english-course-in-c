#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para armazenar os dados do aluno
struct Student {
    int registration_number;
    char name[50];
    char course[50];
    char level[10];
    struct Student* left;
    struct Student* right;
};

// Função para criar um novo nó (aluno)
struct Student* createStudent(int registration_number, const char* name, const char* course, const char* level) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->registration_number = registration_number;
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    strcpy(newStudent->level, level);
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

// Função para inserir um aluno na árvore
struct Student* insertStudent(struct Student* root, int registration_number, const char* name, const char* course, const char* level) {
    if (root == NULL) {
        return createStudent(registration_number, name, course, level);
    }

    if (registration_number < root->registration_number) {
        root->left = insertStudent(root->left, registration_number, name, course, level);
    } else if (registration_number > root->registration_number) {
        root->right = insertStudent(root->right, registration_number, name, course, level);
    }

    return root;
}

// Função para procurar um aluno na árvore
struct Student* searchStudent(struct Student* root, int registration_number) {
    if (root == NULL || root->registration_number == registration_number) {
        return root;
    }

    if (registration_number < root->registration_number) {
        return searchStudent(root->left, registration_number);
    }

    return searchStudent(root->right, registration_number);
}

// Função para exibir todos os alunos em ordem
void displayStudents(struct Student* root) {
    if (root != NULL) {
        displayStudents(root->left);
        printf("Matricula: %d, Nome: %s, Curso: %s, Nivel: %s\n", root->registration_number, root->name, root->course, root->level);
        displayStudents(root->right);
    }
}

int main() {
    struct Student* root = NULL;

    // Inserindo alguns alunos fictícios na árvore
    root = insertStudent(root, 101, "Alice", "Ingles Avancado", "Avancado");
    root = insertStudent(root, 202, "Bob", "Ingles Basico", "Basico");
    root = insertStudent(root, 303, "Charlie", "Ingles Intermediario", "Intermediario");

    int registrationNumberSearch = 202;
    struct Student* foundStudent = searchStudent(root, registrationNumberSearch);
    if (foundStudent != NULL) {
        printf("Student encontrado - Matricula: %d, Nome: %s, Curso: %s, Nivel: %s\n", foundStudent->registration_number, foundStudent->name, foundStudent->course, foundStudent->level);
    } else {
        printf("Student com a matricula %d nao encontrado.\n", registrationNumberSearch);
    }

    printf("\nLista de todos os students cadastrados:\n");
    displayStudents(root);

    // Libera a memória alocada para a árvore 
    free(root);

    return 0;
}


// Include's
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Verificar em qual sistema esta sendo compilado
#if defined(_WIN32) || defined(WIN32) // Windows
#define flush fflush(stdin)
#define clear system("cls")
#else							      // Linux
#include <stdio_ext.h>
#define flush __fpurge(stdin)
#define clear system("clear")
#endif

// Typedef's
typedef struct elementos {
    int nome;
} t_elemento;

typedef struct no {
    struct no * esq;
    t_elemento dado;
    struct no * dir;
} t_no;

typedef t_no* t_arvore;

typedef struct noP{
    t_no * noArv;
    struct noP * prox;
}t_pilha;

typedef t_pilha * pilha;

// Sub rotinas

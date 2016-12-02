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
typedef struct dado{
    int carac;
}t_elemento;

typedef struct noA{
    struct noA * esq;
    t_elemento dado;
    struct noA * dir;
}t_arvore;

typedef t_arvore * arvore;

typedef struct noP{
    t_arvore * noArv;
    struct noP * prox;
}t_pilha;

typedef t_pilha * pilha;

// Sub rotinas
t_arvore * pop(t_pilha ** pilha);
t_arvore * criaA();
pilha criaP();
void preordem_(arvore);
void inordem_(arvore);
void posordem_(arvore);
void push(t_pilha **,t_arvore *);
void inserir(t_arvore ** tree, int carac);
void gotoxy(int coluna, int linha);
void exibirGraficamente(t_arvore * tree, int col, int lin, int desloc);

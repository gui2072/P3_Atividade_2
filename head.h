// Include's
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define's
#define FILE_NAME "dados.csv"

// Verificar em qual sistema esta sendo compilado
#if defined(_WIN32) || defined(WIN32) // Windows
#define flush fflush(stdin)
#define clear system("cls")
#define COL 38
#else							      // Linux
#include <stdio_ext.h>
#define flush __fpurge(stdin)
#define clear system("clear")
#define COL 65
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
void pause();
void openFile(t_arvore *avr);
void gotoxy(int x, int y);
void exibirGraficamente(t_arvore tree, int col, int lin, int desloc);
void exibirPreOrdem(t_arvore tree);
void exibirInOrdem(t_arvore tree);
void exibirPosOrdem(t_arvore tree);
void esvaziar(t_arvore *tree);
int inputInt(char *string1, char *string2);
int isVazia(t_no *no);
int compara(t_elemento dado1, t_elemento dado2);
int inserir(t_arvore *tree, t_elemento item);
int remover (t_arvore *tree, t_elemento item);
t_no * criar();
t_no * busca(t_arvore tree, t_elemento dado);
t_no * buscaSetPai(t_arvore tree, t_elemento dado, t_no ** pai);

#include "lib.h"

#ifdef WIN32
#include <windows.h>
void gotoxy(int coluna, int linha) {
    COORD point;
    point.X = coluna;
    point.Y = linha;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
#else
void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}
#endif

// Exibir a arvore - Procedimento recursivo, usando um percurso pre-ordem.
// sugestao de uso: exibirGraficamente(arvore, 10, 10, 3);
void exibirGraficamente(t_arvore tree, int col, int lin, int desloc) {
    // col e lin sao as coordenadas da tela onde a arvore ira iniciar,
    // ou seja, a posicao da raiz, e desloc representa o deslocamento na tela
    // (em colunas) de um no em relacao ao no anterior.
    if (tree == NULL)
        return; // condicao de parada do procedimento recursivo
    gotoxy(col,lin);
    printf("%d",tree->dado.nome);
    if (tree->esq != NULL)
        exibirGraficamente(tree->esq,col-desloc,lin+2,desloc/2+1);
    if (tree->dir != NULL)
        exibirGraficamente(tree->dir,col+desloc,lin+2,desloc/2+1);
}

void exibirPreOrdem(t_arvore tree) {
    if (tree!=NULL) {
        printf("%d ", tree->dado.nome);
        exibirPreOrdem(tree->esq);
        exibirPreOrdem(tree->dir);
    }
}

void exibirInOrdem(t_arvore tree) {
    if (tree!=NULL) {
        exibirInOrdem(tree->esq);
        printf("%d ", tree->dado.nome);
        exibirInOrdem(tree->dir);
    }
}

void exibirPosOrdem(t_arvore tree){
    if (tree!=NULL) {
        exibirPosOrdem(tree->esq);
        exibirPosOrdem(tree->dir);
        printf("%d ", tree->dado.nome);
    }
}

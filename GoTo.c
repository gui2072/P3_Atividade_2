#include "Lib.h"

#ifdef WIN32
#include <windows.h>
void gotoxy(int coluna, int linha){
    COORD point;
    point.X = coluna;
    point.Y = linha;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
#else
void gotoxy(int x, int y){
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}
#endif


void exibirGraficamente(t_arvore * tree, int col, int lin, int desloc){
    if (tree == NULL)return;
        gotoxy(col,lin);
        printf("%d",tree->dado.carac);
    if (tree->esq != NULL)exibirGraficamente(tree->esq,col-desloc,lin+2,desloc/2+1);
    if (tree->dir != NULL)exibirGraficamente(tree->dir,col+desloc,lin+2,desloc/2+1);
}

#include "head.h"

int main(int argc, char const *argv[]) {
    char input;
    t_arvore avr = NULL;

    openFile(&avr);
    do {
        clear;
        printf("Aluno: Paulo Guilherme Venancio da Silva\nDisciplina: Estrutura de dados I\nProfessor: Walace Bonfim\n\n\t\tEditor de árvore\n\n 1 - Inserir\n 2 - Remover apenas um nó\n 3 - Pesquisar\n 4 - Esvaziar a árvore\n 5 - Exibir a árvore\n 0 - Sair\n\n\tDigite sua opção: ");
        input = getchar();
        flush;

        switch (input) {
            case '0':
                esvaziar(&avr);
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                clear;
                printf("\n\tEsvaziar a árvore\n");
                if (isVazia(avr)){
                    printf("\n\tA árvore esta vazia");
                } else {
                    esvaziar(&avr);
                    printf("\n\tA árvore foi esvaziada");
                }
                pause();
                break;
            case '5':
                clear;
                printf("\n\tExibição da árvore\n");
                if (isVazia(avr)){
                    printf("\n\tA aŕvore esta vazia");
                } else {
                    exibirGraficamente(avr, COL, 4, 4);
                    gotoxy(0, 28);
                    printf("\n\nPre ordem: ");
                    exibirPreOrdem(avr);
                    printf("\n\n In ordem: ");
                    exibirInOrdem(avr);
                    printf("\n\nPos ordem: ");
                    exibirPosOrdem(avr);
                }
                pause();
                break;
        }
    } while('0' != input);
    return 0;
}

#include "head.h"

int main(int argc, char const *argv[]) {
    char input;
    t_elemento elemento;
    t_arvore avr = NULL;

    openFile(&avr);
    do {
        clear;
        printf("Aluno: Paulo Guilherme Venancio da Silva\nDisciplina: Estrutura de dados I\nProfessor: Walace Bonfim\n\n\t    Editor de árvore\n\n 1 - Inserir\n 2 - Remover apenas um nó\n 3 - Pesquisar\n 4 - Esvaziar a árvore\n 5 - Exibir a árvore\n 0 - Sair\n\n\t  Digite sua opção: ");
        input = getchar();
        flush;

        switch (input) {
            case '0':
                clear;
                esvaziar(&avr);
                break;
            case '1':
                clear;
                elemento.nome = inputInt("  Inserir\n","  Digite o elemento: ");
                if (busca(avr, elemento)){
                    printf("\n  O elemento %d ja estar na árvore", elemento.nome);
                    pause();
                } else {
                    while (1){
                        printf("\n  Inserir\n\n  O elemento %d não estar na árvore\n  Deseja inserir o elemento na árvore\n\n   S - Sim\n   N - Não\n\n  Digite uma opção: ", elemento.nome);
                        input = getchar();
                        flush;
                        clear;
                        if (input == 's' || input == 'S'){
                            inserir(&avr, elemento);
                            break;
                        } else if (input == 'n' || input == 'N'){
                            break;
                        }
                    }
                }
                break;
            case '2':
                clear;
                elemento.nome = inputInt("  Remover apenas um nó\n","  Digite o elemento: ");
                if (busca(avr, elemento)){
                    while (1){
                        printf("\n  Inserir\n\n  O elemento %d estar na árvore\n  Deseja inserir o elemento na árvore\n\n   S - Sim\n   N - Não\n\n  Digite uma opção: ", elemento.nome);
                        input = getchar();
                        flush;
                        clear;
                        if (input == 's' || input == 'S'){
                            remover(&avr, elemento);
                            break;
                        } else if (input == 'n' || input == 'N'){
                            break;
                        }
                    }
                } else {
                    printf("\n  O elemento %d não estar na árvore", elemento.nome);
                    pause();
                }
                break;
            case '3':
                clear;
                if (isVazia(avr)){
                    printf("\n  Pesquisa\n\n  A árvore esta vazia");
                } else {
                    elemento.nome = inputInt("  Pesquisa\n","  Digite o elemento: ");
                    printf("\n  Pesquisa\n");
                    if (busca(avr, elemento)){
                        printf("\n  O elemento %d estar na árvore", elemento.nome);
                    } else {
                        printf("\n  O elemento %d não estar na árvore", elemento.nome);
                    }
                }
                pause();
                break;
            case '4':
                clear;
                printf("\n  Esvaziar a árvore\n");
                if (isVazia(avr)){
                    printf("\n  A árvore esta vazia");
                } else {
                    esvaziar(&avr);
                    printf("\n  A árvore foi esvaziada");
                }
                pause();
                break;
            case '5':
                clear;
                printf("\n  Exibição da árvore\n");
                if (isVazia(avr)){
                    printf("\n  A aŕvore esta vazia");
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

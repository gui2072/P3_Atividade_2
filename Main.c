#include "Lib.h"

int main(int argc, char const *argv[]) {
    char input;

    do {
        clear;
        printf("Aluno: Paulo Guilherme Venancio da Silva\nDisciplina: Estrutura de dados I\nProfessor: Walace Bonfim\n\n\t\tEditor de árvore\n\n 1 – Inserir\n 2 – Remover apenas um nó\n 3 – Pesquisar\n 4 – Esvaziar a aŕvore\n 5 – Exibir a árvore\n 0 – Sair\n\n\tDigite sua opção: ");
        flush;
        input = getchar();

        switch (input) {
            case '1':
            break;
            case '2':
            break;
            case '3':
            break;
            case '4':
            break;
            case '5':
            break;
        }
    } while('0' != input);
    return 0;
}

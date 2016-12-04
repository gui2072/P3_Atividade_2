#include "head.h"

void pause() {
    printf("\n\n  Pressione enter para continuar ");
    flush;
    getchar();
    flush;
}

int inputInt(char *string1, char *string2){
    int erro = 0, input = 0;

    do {
        printf("\n%s", string1);
        if (erro == -666){
            printf("\n  Tente novamente, elemento digitado invalido");
        }
        printf("\n%s", string2);
        scanf("%d", &input);
        flush;
        clear;
        if (input){
            erro = 0;
        } else {
            erro = -666;
        }
    } while (erro == -666);
    return input;
}

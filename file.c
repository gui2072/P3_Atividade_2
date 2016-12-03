#include "lib.h"

int openFile(t_arvore * avr){
    t_elemento dado;

    FILE *open = fopen("Input.csv","r");

    while(fscanf(open,"%d",&dado.nome)==1){
        inserir(avr,dado);
        fgetc(open);
    }

    fclose(open);
}

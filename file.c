#include "head.h"

void openFile(t_arvore * avr){
    t_elemento dado;
    FILE *open = fopen(FILE_NAME,"r");

    if (open != NULL) {
        while(fscanf(open,"%d",&dado.nome)==1){
            inserir(avr,dado);
            fgetc(open);
        }
        fclose(open);
    }
}

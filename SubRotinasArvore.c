#include "Lib.h"

void preordem_(arvore arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
    do {
        while (aux != NULL) {
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
            push(&p, aux);
            aux = (aux->esq);
        }
        if (p) {
            aux = pop(&p);
            aux = (aux->dir);
        }
    } while (p->prox || aux);
    printf("\n");
}

void inordem_ (arvore arv) {
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
    do {
        while (aux != NULL) {
            push(&p, aux);
            aux = (aux->esq);
        }
        if (p) {
            aux = pop(&p);
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
            aux = (aux->dir);
        }
    } while (p->prox || aux);
    printf("\n");
}

void posordem_(arvore arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
	int entrou=1;
    do {
        while (aux != NULL && entrou) {
            if(aux->esq){
            	push(&p, aux);
				aux = (aux->esq);
				entrou = 1;
				continue;
			}
            else if (aux->dir){
				push(&p, aux);
				aux = (aux->dir);
				entrou = 1;
				continue;
			}
			entrou = 0;
        }
        if (p) {
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
			if(p->noArv->esq == aux)p->noArv->esq=NULL;
			else if(p->noArv->dir == aux)p->noArv->dir=NULL;
            aux = pop(&p);
			entrou = 1;

        }
    } while (p && (p->prox || aux));
    printf("\n");
}

t_arvore * criaA(){
  t_arvore * no = (t_arvore*)malloc(sizeof(t_arvore));
  if(no)no->esq=no->dir=NULL;
  return no;
}

void inserir(t_arvore ** tree, int carac){
    if(!(*tree)){
        (*tree)=criaA();
        (*tree)->dado.carac=carac;
    }
    else if((*tree)->dado.carac > carac) inserir(&((*tree)->esq),carac);
    else inserir(&((*tree)->dir),carac);
}

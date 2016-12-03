#include "lib.h"

void esvaziar(t_arvore *tree) {
    if (*tree == NULL)
        return;
    esvaziar(&(*tree)->esq);
    esvaziar(&(*tree)->dir);
    free(*tree);
    *tree = NULL;
}

// isVazia - testa se um no eh vazio
int isVazia (t_no * no) {
    return (no == NULL);
}

// Cria um no vazio
t_no * criar () {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->esq = no->dir = NULL;

    return no;
}

t_no * busca(t_arvore tree, t_elemento dado) {
    if (tree == NULL)
        return NULL;
    if (compara(tree->dado, dado)==0)
        return tree;

    if (compara(tree->dado, dado)>0)
        return busca(tree->esq, dado);
    else
        return busca(tree->dir, dado);
}

int compara(t_elemento dado1, t_elemento dado2) {
    if (dado1.nome == dado2.nome){
        return 0;
    } else if (dado1.nome >= dado2.nome) {
        return 1;
    } else {
        return -1;
    }
}
t_no * buscaSetPai(t_arvore tree, t_elemento dado, t_no ** pai) {

    if (tree == NULL) {
        *pai = NULL;
        return NULL;
    }
    if (compara(tree->dado, dado)==0)
        return tree;

    if (compara(tree->dado, dado)>0) {
        *pai = tree;
        return buscaSetPai(tree->esq, dado, pai);
    }
    else {
        *pai = tree;
        return buscaSetPai(tree->dir, dado, pai);
    }
}

int inserir (t_arvore *tree, t_elemento item) {
    int ok;
    // se a raiz for nula, entao insere na raiz
    if (*tree == NULL) {
        *tree = criar();
        if (*tree == NULL)
            return 0;
        (*tree)->dado = item;
        return 1;
    }
    if (compara((*tree)->dado, item)<0)
        ok = inserir (&((*tree)->dir), item);
    else
        if (compara((*tree)->dado, item)>0)
            ok = inserir (&((*tree)->esq), item);
        else
            ok = 0;
    return ok;
}

int remover (t_arvore *tree, t_elemento item) {
    t_no *no, // no aponta para o no a ser removido
        *pai, // pai aponta para o pai do no
        *sub, // sub aponta que ira substituir o no no
        *paiSuce, // pai do no sucessor
        *suce; // sucessor do no no
    no = *tree; pai=NULL;
    // procura o no a ser removido, e seta o seu pai.
    no = buscaSetPai(*tree, item, &pai);
    if (no==NULL)
        return 0; // a chave nao existe na arvore, nao conseguiu remover

    // agora iremos ver os dois primeiros casos, o no tem um filho no maximo
    if (no->esq == NULL)
        sub = no->dir;
    else {
        if (no->dir == NULL)
           sub = no->esq;
           else { // caso em que o no tem dois filhos
               paiSuce=no;
               sub = no->dir;
               suce = sub->esq;   // suce eh sempre o filho esq de sub
               while (suce != NULL) {
                   paiSuce = sub;
                   sub = suce;
                   suce = sub->esq;
               }
               // neste ponto, sub eh o sucessor em ordem de no
               if (paiSuce != no) {
                   //  no nao e o pai de sub, e sub == paiSuce->esq
                   paiSuce->esq = sub->dir;
                   // remove o no sub de sua atual posicao e o
                   // substitui pelo filho direito de sub
                   // sub ocupa o lugar de no
                   sub->dir = no->dir;
               }
               // define o filho esquerdo de sub de modo que sub
               // ocupe o lugar de no
               sub->esq = no->esq;
           }
    }
    // insere sub na posicao ocupada anteriormente por no
    if (pai == NULL) // no eh a raiz, nao tem pai
       *tree = sub;
    else
        // verifica se o no eh o filho da esquerda ou da direita
        if (no == pai->esq)
            pai->esq = sub;
        else
            pai->dir = sub;
    free(no); // libera o no
    return 1; // verdadeiro, conseguiu remover
}

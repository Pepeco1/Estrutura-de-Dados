#include <stdio.h>
#include <stdlib.h>
#include "TLSE.h"

typedef struct ab{          // TIPO ÁRVORE BINÁRIA
    int info;
    struct ab *esq, *dir;
}TAB;

/* Exercícios */

int zigzag(TAB *a);
TLSE* ancestrais(TAB *a, int elem);
TLSE* aux_ancest(TAB* a, TLSE* l, int elem);
int estbin(TAB *a);
int mn(TAB *a1, TAB *a2);


/* Biblioteca básica ABB */
TAB* cria_ab(int x, TAB* e, TAB* d);
void imprime_ab(TAB *t);
void libera_ab(TAB* t);
TAB* busca_ab(int e, TAB* t);
TAB* busca_abb(int e, TAB* t);
TAB* insere_abb(int e, TAB* t);
TAB* retira_abb(int e, TAB *t);


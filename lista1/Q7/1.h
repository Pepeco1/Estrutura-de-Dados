#include <stdio.h>
#include <stdlib.h>

typedef struct ab{              //Struct tipo árvore binária
    int info;
    struct ab *esq, *dir, *pai;
}TAB;

typedef struct lista{           //Struct tipo lista simplesmente encadeada
    int *info;
    struct lista *prox;
}TLSE;


typedef struct pilha{           //Struct tipo pilha
	TLSE *prim;
}TPilha;	




/* OPERAÇÕES BÁSICAS DE PILHA */

void push(TPilha *p, int elem);
int pop(TPilha *p);
int vazia_p(TPilha *p);
TPilha *inicializa_p(void);
void libera_p(TPilha *p);
void imprime_p(TPilha *p);

/* OPERAÇÕES BÁSICAS DE ÁRVORE BINÁRIA */

TAB* inicializa(void);
TAB* cria(int raiz, TAB* esq, TAB* dir);    
void imp_pre(TAB *a);
void imp_sim(TAB *a);
void imp_pos(TAB *a);
void libera(TAB *a);
TAB* busca(TAB* a, int elem);

/* Minhas operações */
void remove_no(TAB* a);             // remove o no da árvore
void copia_no(TAB *a, TAB* b);      // copia a info de "b" para "a"
void aponta_pai(TAB *a, TAB* b);    // troca o ponteiro  no pai que apontava para "a", e o aponta para "b"
int eh_folha(TAB *a);               // retorna 1 se for folha e 0 se não
TAB* encontra_folha(TAB *a);        // retorna uma folha qualquer


/*Q7*/

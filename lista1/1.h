#include <stdio.h>
#include <stdlib.h>

typedef struct ab{              //Struct tipo árvore binária
    int info;
    char cor;
    struct ab *esq, *dir, *pai;
}TAB;


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

/* QUESTÕES */

/*Q1*/TAB* copia(TAB* a);
/*Q2*/TAB* espelho(TAB*a);
/*Q3*/TAB* maior(TAB *a);
/*Q4*/TAB* menor(TAB *a);
/*Q5*/int igual(TAB* a1, TAB* a2);
/*Q6*/void retira_pares(TAB* a);
/*Q7*/void colore (TAB* a); void colore_aux(TAB* a, int cor);
/*Q8*/int ni(TAB *a);
/*Q9*/int nf(TAB* a);


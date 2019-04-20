#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct ab{
int info;
struct ab *esq, *dir;
}TABB;


TABB* inicializa(void);
TABB* cria(int raiz, TABB* esq, TABB* dir);
void imp_pre(TABB *a);
TABB* libera(TABB *a);

TABB* insere_abb(TABB *a, int elem);
TABB* busca_abb(TABB* a, int elem);
TABB* maior(TABB *a);
TABB* menor(TABB *a);
TABB* retira_impares(TABB *a);
TABB* encontra_folha(TABB*a);           //função auxiliar criada para a retira_impares
int* mN(TABB*a, int N);
int * concatena_vet(int* a, int* b);    //função auxiliar criada para mN


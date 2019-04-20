#include "1.h"


TABB* inicializa(void){
    
    return NULL;
    
}

TABB* cria(int raiz, TABB* esq, TABB* dir){
    
    TABB* novo = (TABB*) malloc(sizeof(TABB));
    novo->info = raiz;
    novo->esq = esq;
    novo->dir = dir;
    
    return novo;
    
}


TABB* insere_abb(TABB *a, int elem){

    if(!a) return cria(elem, NULL, NULL);
    if(a->info > elem) a->esq = insere_abb(a->esq, elem);
    else if(a->info < elem) a->dir = insere_abb(a->dir, elem);
    return a;

}


// pré-ordem = raiz, esq e dir.
void imp_pre(TABB *a){
    
    if(a){

        printf("%d \n", a->info);  //imprimindo a info do node atual
        imp_pre(a->esq);           //chamada recursiva para o galho da esquerda
        imp_pre(a->dir);           //chamada recursiva para o galho da direita

    }

}

TABB* libera(TABB *a){

    if(a){
        
        libera(a->esq);
        libera(a->dir);
        free(a);

    }

    return NULL;

}

TABB* busca_abb(TABB* a, int elem){

    if(!a) return NULL;
    if(a->info == elem) return a;
    if(a->info < elem) return busca_abb(a->dir, elem);
    return busca_abb(a->esq, elem);

}

TABB* maior(TABB *a){


    if(!a) return NULL;
    if(!(a->dir)) return a;
    return maior(a->dir);

}

TABB* menor(TABB *a){

    if(!a) return NULL;
    if(!(a->esq)) return a;
    return menor(a->esq);

}


TABB* retira_impares(TABB *a){

    if(!a) return NULL;
    if((a->info) % 2 != 0){

        TABB* folha = encontra_folha(a);
        int aux = folha->info;
        folha->info = a->info;
        a->info = 0;

        TABB* pont_aux = folha;
        libera(pont_aux);
        folha = NULL;


    }
    
    retira_impares(a->esq);
    retira_impares(a->dir);

    return a;
}

TABB* encontra_folha(TABB *a){

    if(!(a->esq) && !(a->dir)) return a;
    return encontra_folha(a->esq); 

}

int* mN(TABB *a, int N){

    if(!a) return NULL;
    int* b = concatena_vet( mN(a->esq, N), mN(a->dir, N) );
    if(a->info < N){       
        int* c = (int*) malloc(sizeof(int));
        c[0] = a->info;
        return c;
    }

}


int * concatena_vet(int* a, int* b){

    int len_a = sizeof(a)/sizeof(int);
    int len_b = sizeof(a)/sizeof(int);

    //int* c = (int*) malloc(sizeof(int)*(len_a + len_b));
    int c[len_a + len_b];
    int i;
    for(i = 0; i < len_a; i++) c[i] = a[i];
    int j = 0;
    for(i ; i < (len_b + len_a); i++){
        
        c[i] = b[j];
        j++;
    
    }

    return c;

}






#include "1.h"

//falta a questão 7 e descobrir se a 6 está certa

/* --------------- QUESTÕES ------------------- */

TAB* copia(TAB* a){

    if(a){
        
        TAB* pesq = inicializa();
        TAB* pdir = inicializa();        

        if(a->esq) pesq = copia(a->esq);
        if(a->dir) pdir = copia(a->dir);
        
        return cria(a->info, pesq, pdir);    
    
    }   

}

TAB* espelho(TAB* a){

    if(a){
        
        TAB* pesq = inicializa();
        TAB* pdir = inicializa();        

        if(a->esq) pesq = copia(a->esq);
        if(a->dir) pdir = copia(a->dir);
        
        return cria(a->info, pdir, pesq);    
    
    }   

}


TAB* maior(TAB* a){

    
    if(!a) return NULL;
    
    TAB* esq = maior(a->esq),
       * dir = maior(a->dir),
       * resp = a;
    
    // se o galho existir e seu elemento for maior que o de resp, substitui
    if((esq) && (esq->info > resp->info)) resp = esq;
    if((dir) && (dir->info > resp->info)) resp = dir;
    
    return resp;
    

}

TAB* menor(TAB* a){

    if(!a) return NULL;

    TAB* esq = menor(a->esq),
       * dir = menor(a->dir),
       * resp = a;

    // se o galho existir e seu elemento for menor que o de resp, substitui
    if((esq) && (esq->info < resp->info)) resp = esq;
    if((dir) && (dir->info < resp->info)) resp = dir;

    return resp;

}

int igual(TAB* a1, TAB* a2){

    if((!a1) && (!a2)) return 1;

    if((!a1) || (!a2)) return 0;

    // verifica em pós-ordem
    int resp1 = igual(a1->esq, a2->esq);
    resp2 = igual(a1->dir, a2->dir);

    if(a1->info == a2->info) return resp1 && resp2;   // se as informações forem iguais, retorna and entre os resp

    return 0;                               // se não, retorna 0

}


void retira_pares(TAB* a){

    if(!a) return;             //retorna nulo se não existir

    if((a->info)%2 == 0){    // se for par

        remove_no(a);

    }
    
    if(a->dir) retira_pares(a->dir);
    if(a->esq) retira_pares(a->esq);

}

void colore (TAB* a){

    int cor = 0;

    colore_aux(a, cor);

}

void colore_aux(TAB* a, int cor){

    if(!a) return;

    if(cor == 0){

        a->cor = 'P';
        cor = 1;

    }

    else if(cor == 1){

        a->cor = 'V';
        cor = 0;

    } 

    colore_aux(a->esq, cor);
    colore_aux(a->dir, cor);


}



int ni(TAB *a){

    if(!a) return 0;
    
    int resp = 1;
        resp += ni(a->esq);
        resp += ni(a->dir);

    return resp;

}

int nf(TAB* a){

    if(!a) return 0;

    if(eh_folha(a)) return 1;
    

    int resp = 0;
        resp += nf(a->esq);
        resp += nf(a->dir);
    

    return resp;
}




/* -------------- FUNÇÕES TIPO ÁRVORE BINÁRIA --------------- */

TAB* inicializa(void){
    
    return NULL;
    
}

TAB* cria(int raiz, TAB* esq, TAB* dir){
    
    TAB* novo = (TAB*) malloc(sizeof(TAB));
    novo->info = raiz;
    novo->esq = esq;
    novo->dir = dir;
    novo->pai = NULL;

    if(esq) esq->pai = novo;
    if(dir) dir->pai = novo;
    
    return novo;
    
}


// pré-ordem = raiz, esq e dir.
void imp_pre(TAB *a){
    
    if(a){
        printf("%d \n", a->info);     //imprimindo a info do node atual
        imp_pre(a->esq);           //chamada recursiva para o galho da esquerda
        imp_pre(a->dir);           //chamada recursiva para o galho da direita
    }

}

// simétrico = esq, raiz e dir
void imp_sim(TAB *a){

    if(a){    
        imp_sim(a->esq);            //chamada recursiva para o galho da esquerda
        printf("%d\n", a->info);      //imprimindo a info do node atual
        imp_sim(a->dir);            //chamada recursiva para o galho da direita
    }
}

// pós-ordem = esq, dir e raiz
void imp_pos(TAB *a){

    if(a){
        imp_pos(a->esq);           //chamada recursiva para o galho da esquerda
        imp_pos(a->dir);           //chamada recursiva para o galho da direita
        printf("%d\n", a->info);     //imprimindo a info do node atual
    }

}

void libera(TAB *a){

    TAB* p1;
    if(p1){
        libera(p1->esq);            //chamada recursiva para o galho da esquerda
        libera(p1->dir);            //chamada recursiva para o galho da direita
        free(p1);                   //libera o node atual
    }

}

TAB* busca(TAB* a, int elem){

    if((!a)||(a->info == elem)) return a;
    TAB* resp = busca(a->esq,elem);
    
    if(resp) return resp;

    return busca(a->dir, elem);

}


TAB* encontra_folha(TAB *a){

    if(eh_folha(a)) return a;

    if(a->esq) return encontra_folha(a->esq);
    if(a->dir) return encontra_folha(a->dir); 

}

void remove_no(TAB *a){

    if(!a) return;

    if(a->dir){

        copia_no(a, a->dir);
        remove_no(a->dir);

    }

    else if(a->esq){

        copia_no(a, a->esq);
        remove_no(a->esq);

    }

    else{

        aponta_pai(a, NULL);
        free(a);

    }

}

void aponta_pai(TAB* a, TAB* b){    //o pai de "a" vai apontar para "b" em seu lugar

    if(!a) return;

    if(a->pai){

        if(a->pai->esq == a) a->pai->esq = b;
        else if(a->pai->dir == a) a->pai->dir = b;

    }

}

void copia_no(TAB* a, TAB* b){

    a->info = b->info;

}

int eh_folha(TAB* a){     //verifica se é folha
    
    if((!a->esq) && (!a->dir)) return 1;
    return 0;

}


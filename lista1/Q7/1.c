#include "1.h"

//falta a questão 7 e descobrir se a 6 está certa

/* --------------- QUESTÕES ------------------- */




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



/* -----------FUNÇÕES TIPO PILHA ----------------*/
TPilha *inicializa_p(void){
	TPilha *p = (TPilha *)malloc(sizeof(TPilha));
	p->prim = NULL;
	return p;
}
	
int vazia_p(TPilha *p){
	return (p->prim == NULL);
}
	
void push(TPilha *p,int elem){
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = elem;
	novo->prox = p->prim;
	p->prim = novo;
}

int pop(TPilha *p){
	if (!vazia_p(p)){
		TLSE *aux = p->prim;
		int x = aux->info;
		p->prim = aux->prox;
		free(aux);
		return x;
	}
	else{ // pilha vazia
		exit(1);
	}
}

void libera_p(TPilha *p){
	TLSE *q = p->prim,*r ;
	while(q){
		r = q;
		q=q->prox;
		free(r);
	}
	free(p);
}

void imprime_p(TPilha *p){
 	TPilha *aux = inicializa_p();
	while (!vazia_p(p)){
		int x = pop(p);
		printf("%d ",x);
		push(aux,x);
	}
	while(!vazia_p(aux)){
		push(p,pop(aux));
	}
	
	libera_p(aux);
}







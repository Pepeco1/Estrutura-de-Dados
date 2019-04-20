#include "TAB_TABB.h"


/* Exercícios */

int zigzag(TAB *a){     //retorna 1 se for zigzag

  if(!a) return 0;

  if(a->esq && a->dir) return 0;  

  if(a->esq && (!a->dir)) return zigzag(a->esq);
  if(a->dir && (!a->esq)) return zigzag(a->dir);

  return 1;

}

TLSE* ancestrais(TAB *a, int elem){

  if(!a) return NULL;

  TLSE* l = NULL;

  l = aux_ancest(a, l, elem);

}

TLSE* aux_ancest(TAB* a, TLSE* l, int elem){

  if(!a) return NULL;

  if(a->info < elem){

    l = inserel(l, a->info);
    aux_ancest(a->dir, l, elem);

  }
  if(a->info > elem){

    l = inserel(l, a->info);
    aux_ancest(a->esq, l, elem);

  }

  return l;

}

int estbin(TAB *a){

  if(!a) return 0;

  if((a->esq && a->dir) || ((!a->esq) && (!a->dir))){
    
    if(a->esq && a->dir) return estbin(a->esq) && estbin(a->dir);
    return 1;                                                     //se for estbin retorna 1

  }

  return 0;                                                       //se não, retorna 0


}

int mn(TAB *a1, TAB *a2){

  if(!a1) return 0;

  int resp;
  int aux1 = 1;
  int aux2 = 1; 

  if(a1->esq) aux1 = mn(a1->esq, a2);
  if(a1->dir) aux2 = mn(a1->dir, a2);

  resp = aux1 && aux2;


  TAB* aux;

  aux = busca_ab(a1->info, a2);


  if(aux && resp){

    return 1;

  }

  return 0;

}


/* BIBLIOTECA BÁSICA ABB */

void libera_ab(TAB* t){
  if(t){
  libera_ab(t->esq);
  libera_ab(t->dir);
  free(t);
  }
}

TAB* busca_abb(int e, TAB* t){
  if(!t) return NULL;
  if(e < t->info) return busca_abb(e, t->esq);
  if(e > t->info) return busca_abb(e, t->dir);
  return t;
}

TAB* busca_ab(int e, TAB* t){
  if((!t) || (t->info == e)) return t;
  TAB *resp = busca_ab(e, t->esq);
  if(resp) return resp;
  return busca_ab(e, t->dir);
}

void imprime_aux(TAB* a, int andar){
  if(a){
    int j;
    imprime_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("   ");
    printf("%d\n", a->info);
    imprime_aux(a->dir, andar + 1);
  }
}

void imprime_ab(TAB* a){
  imprime_aux(a, 1);
}

TAB* cria_ab(int x, TAB* e, TAB* d){
  TAB* a = (TAB*) malloc(sizeof(TAB));
  a->info = x;
  a->esq = e;
  a->dir = d;
  return a;
}

TAB* insere_abb(int e, TAB* t){
  if(!t) t = cria_ab(e, NULL, NULL);
  else if(e < t->info) t->esq = insere_abb(e, t->esq);
  else if(e > t->info) t->dir = insere_abb(e, t->dir);
  return t;
}

TAB* retira_abb(int e, TAB *t){
  if(!t) return t;
  else if(e < t->info) t->esq = retira_abb(e, t->esq);
  else if(e > t->info) t->dir = retira_abb(e, t->dir);
  else{
    if((!t->esq) && (!t->dir)){
      free(t);
      t = NULL;
    }
    else if((!t->esq) || (!t->dir)){
      TAB *q = t;
      if(!t->dir) t = t->esq;
      else t = t->dir;
      free(q); 
    }
    else{
      TAB *f = t->esq;
      while(f->dir) f = f->dir;
      t->info = f->info;
      f->info = e;
      t->esq = retira_abb(e, t->esq);
    }
  }
  return t;  
}

#include "TG.h"

TG *inicializa(){
  return NULL;
}


void imprime(TG *g){
  while(g){
    printf("No %d\n", g->id_no);
    printf("vizinhos: ");
    TVIZ *v = g->prim_viz;
    while(v){
      printf("%d ", v->id_viz);
      v = v->prox_viz;
    }
    printf("\n\n");
    g = g->prox_no;
  }
}

void imp_rec(TG *g){
  if(g){
    printf("%d:\n", g->id_no);
    TVIZ *v = g->prim_viz;
    while(v){
      printf("%d ", v->id_viz);
      v = v->prox_viz;
    }
    imp_rec(g->prox_no);
  }
}

void libera_viz(TVIZ *v){
  while(v){
    TVIZ *temp = v;
    v = v->prox_viz;
    free(temp);
  }
}

void libera_viz_rec(TVIZ *v){
  if(!v) return;
  libera_viz_rec(v->prox_viz);
  free(v);
}

void libera(TG *g){
  while(g){
    libera_viz(g->prim_viz);
    TG *temp = g;
    g = g->prox_no;
    free(temp);
  }
}

void libera_rec(TG *g){
  if(g){
    libera_viz(g->prim_viz);
    libera_rec(g ->prox_no);
    free(g);
  }
}

TG* busca_no(TG* g, int x){
  if((!g) || (g->id_no == x)) return g;
  return(busca_no(g->prox_no, x));
}

TVIZ* busca_aresta(TG *g, int no1, int no2){
  TG *p1 = busca_no(g,no1), *p2 = busca_no(g,no2);
  if((!p1) || (!p2)) return NULL;
  TVIZ *resp = p1->prim_viz;
  while((resp) && (resp->id_viz != no2)) resp = resp->prox_viz;
  return resp;
}

TG *ins_no(TG *g, int x){
  TG *p = busca_no(g, x);
  if(!p){
    p = (TG*) malloc(sizeof(TG));
    p->id_no = x;
    p->prox_no = g;
    p->prim_viz = NULL;
    g = p;
  }
  return p;
}

void ins_um_sentido(TG *g, int no1, int no2){
  TG *p = busca_no(g, no1);
  TVIZ *nova = (TVIZ *) malloc(sizeof(TVIZ));
  nova->id_viz = no2;
  nova->prox_viz = p->prim_viz;
  p->prim_viz = nova;
}

void ins_aresta(TG *g, int no1, int no2){
  TVIZ *v = busca_aresta(g, no1, no2);
  if(v) return;
  ins_um_sentido(g, no1, no2);
  ins_um_sentido(g, no2, no1);
}

void retira_um_sentido(TG *g, int no1, int no2){
  TG *p = busca_no(g, no1);
  if(!p) return;
  TVIZ *ant = NULL, *atual = p->prim_viz;
  while((atual)&&(atual->id_viz != no2)){
    ant = atual;
    atual = atual->prox_viz;
  }
  if(!ant) p->prim_viz = atual ->prox_viz;
  else ant->prox_viz = atual->prox_viz;
  free(atual);
}

void retira_aresta(TG *g ,int no1, int no2){
  TVIZ* v = busca_aresta(g,no1,no2);
  if(!v) return;
  retira_um_sentido(g,no1,no2);
  retira_um_sentido(g,no2,no1);
}

TG *retira_no(TG *g, int no){
  TG *p = g, *ant = NULL;
  while((p)&& (p->id_no != no)){
    ant = p;
    p = p->prox_no;
  }
  if(!p) return g;
  while(p->prim_viz) retira_aresta(g, no, p->prim_viz->id_viz);
  if(!ant) g = g->prox_no;
  else ant->prox_no = p->prox_no;
  free(p);
  return g;
}


int testek(TG *g, int k){

  int contador = 0;
  TG *auxgraf = g;

  while (auxgraf){
  TVIZ *auxviz =  auxgraf->prim_viz;
    int contador = 0;

    while(auxviz){

      contador++;
      auxviz = auxviz->prox_viz;

    }
    if(contador != k) return 0;

    auxgraf = auxgraf->prox_no;
  }
  return 1;

}

int ig(TG *g1, TG *g2){

  TG* aux1 = g1;
  TG* aux2 = g2;

  while(g1){

    aux2 = busca_no(g2, g1->id_no)
    if(!aux2) return 0;

    TVIZ auxviz1 = g1->prim_viz;

    while(auxviz1){

      TVIZ viz = busca_aresta(g2, g1->id_no, auxviz1->id_viz);
      if(!viz) return 0;

    }
  }
  return 1;

}


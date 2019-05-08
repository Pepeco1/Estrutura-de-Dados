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
      printf("nome: %d\n", v->id_viz);
      printf("idade %d", v->idade_viz);
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
  while((resp) && (resp->id_viz != no2)){
    
    if(resp->id_viz == no2) return resp;
    resp = resp->prox_viz;

  }
  return NULL;
}

TG *ins_no(TG *g, int x, int idade){
  TG *p = busca_no(g, x);
  if(!p){
    p = (TG*) malloc(sizeof(TG));
    p->id_no = x;
    p->idade_no = idade;
    p->prox_no = g;
    p->prim_viz = NULL;
    g = p;
  }
  return p;
}

void ins_um_sentido(TG *g, int no1, int no2){
  TG *p = busca_no(g, no1);
  TG *p2 = busca_no(g, no2);
  TVIZ *nova = (TVIZ *) malloc(sizeof(TVIZ));
  nova->id_viz = p2->id_no;
  nova->idade_viz = p2->idade_no;
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

  int grafo_igual = 0;

  while(g1){

    TG *auxTG;
    auxTG = busca_no(g2, g1->id_no);
    if(!auxTG) return 0;              //se não tiver um nó igual em g2 retorna 0;
    TVIZ *auxviz1 = g1->prim_viz;

    while(auxviz1){
      TVIZ *auxviz2 = auxTG->prim_viz;
      int tem_igual = 0;

      while(auxviz2){
        
        if(auxviz1->id_viz == auxviz2->id_viz) tem_igual = 1;
        auxviz2 = auxviz2->prox_viz;
        
      }

      if(!tem_igual) return 0;        //se em algum caso não achar um vizinho igual, o grafo não é igual, então retorna 0;
      auxviz1 = auxviz1->prox_viz;    
    }

    g1 = g1->prox_no;

  }
  return 1;

}


int numero_seguidos(TG *grafo, int id){

  TG *p1 = busca_no(grafo, id);

  int contador = 0;
  TVIZ *aux = p1->prim_viz;

  while(aux){

    contador++;
    aux = aux->prox_viz;

  }

  return contador;

}

int seguidores(TG *g, int id, int imprime){

  if(!g) return -1;

  int contador = 0;

  while(g){

    TVIZ *aux_viz = g->prim_viz;

    while(aux_viz){

      if(aux_viz->id_viz == id){

        contador++;
        if(imprime) printf("seguidor: %d \n", g->id_no);

      }
      aux_viz = aux_viz->prox_viz;

    }

    g = g->prox_no;

  }
  
  return contador;
}


TG *mais_popular(TG *g){

  if(!g) return NULL;

  TG *popular = g;
  int popular_seg;
  popular_seg = seguidores(g, popular->id_no, 0);
  g = g->prox_no;

  while(g){

    int seg;
    seg = seguidores(g, g->id_no, 0);

    if(seg > popular_seg){
      popular = g;
      popular_seg = seg;
    }

    g = g->prox_no;
  }

  return popular;

}